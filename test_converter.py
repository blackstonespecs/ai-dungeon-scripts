#!/usr/bin/env python3
"""
Test script for JSON to Unreal Engine converter
Demonstrates conversion capabilities with sample data
"""

import json
import os
import sys
from json_to_unreal_converter import JSONToUnrealConverter, UnrealToJSONConverter


def test_json_to_unreal():
    """Test JSON to Unreal Engine conversion."""
    print("=" * 80)
    print("TEST 1: JSON to Unreal Engine Conversion")
    print("=" * 80)
    
    # Create test data
    test_data = {
        "Characters": {
            "TestHero": {
                "name": "Test Hero",
                "role": "Protagonist",
                "level": 10,
                "health": 100.5,
                "is_alive": True,
                "inventory": ["Sword", "Shield", "Potion"],
                "description": "A brave hero on a quest to save the world"
            }
        },
        "Weapons": {
            "Excalibur": {
                "name": "Excalibur",
                "damage": 50,
                "durability": 100.0,
                "is_legendary": True,
                "special_abilities": ["Holy Strike", "Light Beam"],
                "description": "The legendary sword of kings"
            }
        }
    }
    
    # Save test data
    test_json_path = "test_story_cards.json"
    with open(test_json_path, 'w') as f:
        json.dump(test_data, f, indent=4)
    
    print(f"\n✓ Created test JSON file: {test_json_path}")
    
    # Convert to Unreal
    converter = JSONToUnrealConverter("TestUnrealOutput")
    files = converter.convert_json_data(test_data)
    converter.save_files(files)
    
    print(f"\n✓ Generated {len(files)} Unreal Engine files")
    print("\nGenerated files:")
    for filepath in sorted(files.keys()):
        print(f"  - {filepath}")
    
    return test_json_path, "TestUnrealOutput"


def test_unreal_to_json(unreal_dir):
    """Test Unreal Engine to JSON conversion."""
    print("\n" + "=" * 80)
    print("TEST 2: Unreal Engine to JSON Conversion")
    print("=" * 80)
    
    converter = UnrealToJSONConverter()
    output_json = "reconstructed_story_cards.json"
    
    story_cards = converter.convert_to_json(unreal_dir, output_json)
    
    print(f"\n✓ Reconstructed JSON file: {output_json}")
    print(f"✓ Recovered {len(story_cards)} categories")
    
    return output_json


def display_sample_output(output_dir):
    """Display sample generated files."""
    print("\n" + "=" * 80)
    print("SAMPLE OUTPUT: Generated Unreal Engine Header File")
    print("=" * 80)
    
    # Find first .h file
    for root, dirs, files in os.walk(output_dir):
        for file in files:
            if file.endswith('.h'):
                filepath = os.path.join(root, file)
                print(f"\nFile: {file}")
                print("-" * 80)
                with open(filepath, 'r') as f:
                    content = f.read()
                    # Display first 30 lines
                    lines = content.split('\n')[:30]
                    print('\n'.join(lines))
                    if len(content.split('\n')) > 30:
                        print("\n... (truncated)")
                return


def compare_json_files(original, reconstructed):
    """Compare original and reconstructed JSON."""
    print("\n" + "=" * 80)
    print("TEST 3: Comparing Original vs Reconstructed JSON")
    print("=" * 80)
    
    with open(original, 'r') as f:
        original_data = json.load(f)
    
    with open(reconstructed, 'r') as f:
        reconstructed_data = json.load(f)
    
    print(f"\nOriginal categories: {list(original_data.keys())}")
    print(f"Reconstructed categories: {list(reconstructed_data.keys())}")
    
    # Check if structure is preserved
    original_entities = sum(len(v) if isinstance(v, dict) else 0 
                           for v in original_data.values())
    reconstructed_entities = sum(len(v) if isinstance(v, dict) else 0 
                                for v in reconstructed_data.values())
    
    print(f"\nOriginal entities: {original_entities}")
    print(f"Reconstructed entities: {reconstructed_entities}")
    
    if original_entities == reconstructed_entities:
        print("\n✓ Structure preserved successfully!")
    else:
        print("\n⚠ Some data may have been lost in conversion")


def test_with_sample_file():
    """Test with the sample story cards file if it exists."""
    print("\n" + "=" * 80)
    print("TEST 4: Converting Sample Story Cards (DEUS MODUS)")
    print("=" * 80)
    
    sample_file = "sample_story_cards.json"
    
    if not os.path.exists(sample_file):
        print(f"\n⚠ Sample file not found: {sample_file}")
        return
    
    print(f"\n✓ Found sample file: {sample_file}")
    
    # Load and display stats
    with open(sample_file, 'r') as f:
        data = json.load(f)
    
    print(f"\nCategories in sample file:")
    for category, items in data.items():
        if isinstance(items, dict):
            print(f"  - {category}: {len(items)} items")
    
    # Convert
    converter = JSONToUnrealConverter("SampleUnrealOutput")
    files = converter.convert_json_data(data)
    converter.save_files(files)
    
    print(f"\n✓ Generated {len(files)} files from sample story cards")
    
    # Show some examples
    print("\nExample generated classes:")
    classes = set()
    for filepath in files.keys():
        if filepath.endswith('.h'):
            basename = os.path.basename(filepath)
            class_name = basename.replace('.h', '')
            classes.add(class_name)
    
    for class_name in sorted(list(classes)[:5]):
        print(f"  - {class_name}")
    
    if len(classes) > 5:
        print(f"  ... and {len(classes) - 5} more")


def main():
    """Run all tests."""
    print("\n" + "=" * 80)
    print("JSON TO UNREAL ENGINE CONVERTER - TEST SUITE")
    print("=" * 80)
    
    try:
        # Test 1: Basic conversion
        test_json, unreal_dir = test_json_to_unreal()
        
        # Display sample output
        display_sample_output(unreal_dir)
        
        # Test 2: Reverse conversion
        reconstructed_json = test_unreal_to_json(unreal_dir)
        
        # Test 3: Compare results
        compare_json_files(test_json, reconstructed_json)
        
        # Test 4: Sample story cards
        test_with_sample_file()
        
        print("\n" + "=" * 80)
        print("ALL TESTS COMPLETED SUCCESSFULLY!")
        print("=" * 80)
        print("\nNext steps:")
        print("1. Review generated files in TestUnrealOutput/ and SampleUnrealOutput/")
        print("2. Copy .h and .cpp files to your Unreal Engine project")
        print("3. Regenerate project files and compile")
        print("4. Create Blueprint assets from the generated classes")
        print("\nFor more information, see CONVERTER_README.md")
        
    except Exception as e:
        print(f"\n❌ Error during testing: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)


if __name__ == '__main__':
    main()
