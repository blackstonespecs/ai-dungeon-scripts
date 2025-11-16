#!/usr/bin/env python3
"""
JSON Story Cards to Unreal Engine Script Converter
Converts JSON story card data to Unreal Engine C++ and Blueprint formats, and vice versa.
"""

import json
import os
import re
from typing import Dict, List, Any, Optional
from datetime import datetime


class UnrealScriptGenerator:
    """Generates Unreal Engine C++ and Blueprint script from JSON story cards."""
    
    def __init__(self):
        self.indent_level = 0
        self.indent_char = "    "
    
    def indent(self) -> str:
        """Return current indentation string."""
        return self.indent_char * self.indent_level
    
    def sanitize_name(self, name: str) -> str:
        """Convert name to valid C++ identifier."""
        # Remove special characters and spaces
        sanitized = re.sub(r'[^a-zA-Z0-9_]', '', name.replace(' ', '_'))
        # Ensure it doesn't start with a number
        if sanitized and sanitized[0].isdigit():
            sanitized = 'N' + sanitized
        return sanitized or 'UnnamedEntity'
    
    def generate_header_file(self, entity_type: str, entity_data: Dict[str, Any]) -> str:
        """Generate Unreal Engine C++ header file (.h)."""
        class_name = f"U{self.sanitize_name(entity_data.get('name', entity_type))}"
        
        header = f"""// Generated from JSON Story Card
// Entity Type: {entity_type}
// Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "{class_name}.generated.h"

/**
 * {entity_data.get('description', 'Story card entity')}
 */
UCLASS(BlueprintType, Blueprintable)
class {class_name} : public UDataAsset
{{
    GENERATED_BODY()

public:
    {class_name}();

"""
        
        # Generate properties from JSON data
        for key, value in entity_data.items():
            if key in ['name', 'type']:
                continue
            
            property_name = self.sanitize_name(key)
            unreal_type = self.get_unreal_type(value)
            
            header += f"    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Story Card\")\n"
            header += f"    {unreal_type} {property_name};\n\n"
        
        header += "};\n"
        return header
    
    def generate_cpp_file(self, entity_type: str, entity_data: Dict[str, Any]) -> str:
        """Generate Unreal Engine C++ implementation file (.cpp)."""
        class_name = f"U{self.sanitize_name(entity_data.get('name', entity_type))}"
        
        cpp = f"""// Generated from JSON Story Card
// Entity Type: {entity_type}

#include "{class_name}.h"

{class_name}::{class_name}()
{{
"""
        
        # Initialize properties with default values from JSON
        for key, value in entity_data.items():
            if key in ['name', 'type']:
                continue
            
            property_name = self.sanitize_name(key)
            default_value = self.get_cpp_default_value(value)
            
            if default_value:
                cpp += f"    {property_name} = {default_value};\n"
        
        cpp += "}\n"
        return cpp
    
    def generate_blueprint_data(self, entity_type: str, entity_data: Dict[str, Any]) -> Dict[str, Any]:
        """Generate Blueprint-compatible JSON structure."""
        blueprint = {
            "Type": "Blueprint",
            "Class": f"U{self.sanitize_name(entity_data.get('name', entity_type))}",
            "ParentClass": "/Script/Engine.DataAsset",
            "Properties": {}
        }
        
        for key, value in entity_data.items():
            property_name = self.sanitize_name(key)
            blueprint["Properties"][property_name] = {
                "Type": self.get_unreal_type(value),
                "Value": value
            }
        
        return blueprint
    
    def get_unreal_type(self, value: Any) -> str:
        """Map Python/JSON type to Unreal Engine type."""
        if isinstance(value, bool):
            return "bool"
        elif isinstance(value, int):
            return "int32"
        elif isinstance(value, float):
            return "float"
        elif isinstance(value, str):
            return "FString"
        elif isinstance(value, list):
            if value and isinstance(value[0], str):
                return "TArray<FString>"
            elif value and isinstance(value[0], dict):
                return "TArray<FStoryCardData>"
            else:
                return "TArray<FString>"
        elif isinstance(value, dict):
            return "FStoryCardData"
        else:
            return "FString"
    
    def get_cpp_default_value(self, value: Any) -> Optional[str]:
        """Convert Python value to C++ default value."""
        if isinstance(value, bool):
            return "true" if value else "false"
        elif isinstance(value, int):
            return str(value)
        elif isinstance(value, float):
            return f"{value}f"
        elif isinstance(value, str):
            # Escape quotes and special characters
            escaped = value.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
            return f'TEXT("{escaped}")'
        elif isinstance(value, (list, dict)):
            return None  # Complex types need manual initialization
        else:
            return None


class JSONToUnrealConverter:
    """Main converter class for JSON to Unreal Engine scripts."""
    
    def __init__(self, output_dir: str = "UnrealOutput"):
        self.output_dir = output_dir
        self.generator = UnrealScriptGenerator()
        os.makedirs(output_dir, exist_ok=True)
    
    def convert_json_file(self, json_path: str) -> Dict[str, str]:
        """Convert JSON file to Unreal Engine scripts."""
        with open(json_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        
        return self.convert_json_data(data)
    
    def convert_json_data(self, data: Dict[str, Any]) -> Dict[str, str]:
        """Convert JSON data structure to Unreal Engine scripts."""
        output_files = {}
        
        # Process each top-level category in the JSON
        for category, items in data.items():
            if isinstance(items, dict):
                # Process each item in the category
                for item_name, item_data in items.items():
                    if isinstance(item_data, dict):
                        files = self.generate_entity_files(category, item_name, item_data)
                        output_files.update(files)
            elif isinstance(items, list):
                # Process list of items
                for idx, item_data in enumerate(items):
                    if isinstance(item_data, dict):
                        item_name = item_data.get('name', f'{category}_{idx}')
                        files = self.generate_entity_files(category, item_name, item_data)
                        output_files.update(files)
        
        return output_files
    
    def generate_entity_files(self, category: str, name: str, data: Dict[str, Any]) -> Dict[str, str]:
        """Generate all files for a single entity."""
        entity_data = {'name': name, 'type': category, **data}
        class_name = f"U{self.generator.sanitize_name(name)}"
        
        files = {}
        
        # Generate header file
        header_content = self.generator.generate_header_file(category, entity_data)
        header_path = os.path.join(self.output_dir, f"{class_name}.h")
        files[header_path] = header_content
        
        # Generate cpp file
        cpp_content = self.generator.generate_cpp_file(category, entity_data)
        cpp_path = os.path.join(self.output_dir, f"{class_name}.cpp")
        files[cpp_path] = cpp_content
        
        # Generate blueprint data
        blueprint_data = self.generator.generate_blueprint_data(category, entity_data)
        blueprint_path = os.path.join(self.output_dir, f"{class_name}_BP.json")
        files[blueprint_path] = json.dumps(blueprint_data, indent=4)
        
        return files
    
    def save_files(self, files: Dict[str, str]):
        """Save generated files to disk."""
        for filepath, content in files.items():
            os.makedirs(os.path.dirname(filepath), exist_ok=True)
            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(content)
            print(f"Generated: {filepath}")


class UnrealToJSONConverter:
    """Converter for Unreal Engine scripts back to JSON story cards."""
    
    def __init__(self):
        self.data = {}
    
    def parse_header_file(self, header_path: str) -> Dict[str, Any]:
        """Parse Unreal Engine header file to extract data."""
        with open(header_path, 'r', encoding='utf-8') as f:
            content = f.read()
        
        entity_data = {}
        
        # Extract class name
        class_match = re.search(r'class\s+(\w+)\s*:', content)
        if class_match:
            entity_data['class_name'] = class_match.group(1)
        
        # Extract properties
        property_pattern = r'UPROPERTY\([^)]+\)\s+(\w+(?:<[^>]+>)?)\s+(\w+);'
        properties = re.findall(property_pattern, content)
        
        for prop_type, prop_name in properties:
            entity_data[prop_name] = {
                'type': prop_type,
                'value': None  # Will be filled from cpp or blueprint
            }
        
        return entity_data
    
    def parse_blueprint_json(self, blueprint_path: str) -> Dict[str, Any]:
        """Parse Blueprint JSON file."""
        with open(blueprint_path, 'r', encoding='utf-8') as f:
            return json.load(f)
    
    def convert_to_json(self, unreal_dir: str, output_path: str):
        """Convert Unreal Engine scripts back to JSON story cards."""
        story_cards = {}
        
        # Find all blueprint JSON files
        for root, dirs, files in os.walk(unreal_dir):
            for file in files:
                if file.endswith('_BP.json'):
                    blueprint_path = os.path.join(root, file)
                    blueprint_data = self.parse_blueprint_json(blueprint_path)
                    
                    # Extract entity information
                    class_name = blueprint_data.get('Class', '')
                    properties = blueprint_data.get('Properties', {})
                    
                    # Convert properties back to simple format
                    entity = {}
                    for prop_name, prop_data in properties.items():
                        entity[prop_name] = prop_data.get('Value')
                    
                    # Organize by type/category
                    entity_type = entity.get('type', 'Entities')
                    entity_name = entity.get('name', class_name)
                    
                    if entity_type not in story_cards:
                        story_cards[entity_type] = {}
                    
                    story_cards[entity_type][entity_name] = entity
        
        # Save to JSON
        with open(output_path, 'w', encoding='utf-8') as f:
            json.dump(story_cards, f, indent=4)
        
        print(f"Converted to JSON: {output_path}")
        return story_cards


def main():
    """Main entry point for the converter."""
    import argparse
    
    parser = argparse.ArgumentParser(
        description='Convert JSON Story Cards to Unreal Engine scripts and vice versa'
    )
    parser.add_argument(
        'mode',
        choices=['json2unreal', 'unreal2json'],
        help='Conversion mode'
    )
    parser.add_argument(
        'input',
        help='Input file or directory path'
    )
    parser.add_argument(
        '-o', '--output',
        default=None,
        help='Output directory or file path'
    )
    
    args = parser.parse_args()
    
    if args.mode == 'json2unreal':
        output_dir = args.output or 'UnrealOutput'
        converter = JSONToUnrealConverter(output_dir)
        
        print(f"Converting JSON to Unreal Engine scripts...")
        print(f"Input: {args.input}")
        print(f"Output: {output_dir}")
        
        files = converter.convert_json_file(args.input)
        converter.save_files(files)
        
        print(f"\nConversion complete! Generated {len(files)} files.")
    
    elif args.mode == 'unreal2json':
        output_file = args.output or 'story_cards.json'
        converter = UnrealToJSONConverter()
        
        print(f"Converting Unreal Engine scripts to JSON...")
        print(f"Input: {args.input}")
        print(f"Output: {output_file}")
        
        converter.convert_to_json(args.input, output_file)
        
        print(f"\nConversion complete!")


if __name__ == '__main__':
    main()
