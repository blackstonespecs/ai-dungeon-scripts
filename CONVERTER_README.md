# JSON Story Cards to Unreal Engine Script Converter

A comprehensive Python tool for converting JSON story card data into Unreal Engine C++ and Blueprint formats, with bidirectional conversion support.

## Features

- **JSON to Unreal Engine**: Convert story card JSON data into:
  - C++ Header files (.h)
  - C++ Implementation files (.cpp)
  - Blueprint-compatible JSON data
  
- **Unreal Engine to JSON**: Convert Unreal Engine scripts back to JSON story cards

- **Automatic Type Mapping**: Intelligently maps JSON data types to Unreal Engine types:
  - `bool` → `bool`
  - `int` → `int32`
  - `float` → `float`
  - `string` → `FString`
  - `array` → `TArray<T>`
  - `object` → `FStoryCardData`

- **Blueprint Support**: Generates Blueprint-compatible data structures

- **Safe Name Conversion**: Automatically sanitizes names to valid C++ identifiers

## Installation

### Prerequisites

- Python 3.7 or higher
- Unreal Engine 4.x or 5.x (for using generated scripts)

### Setup

```bash
# No additional dependencies required - uses Python standard library only
python3 json_to_unreal_converter.py --help
```

## Usage

### Convert JSON to Unreal Engine Scripts

```bash
python3 json_to_unreal_converter.py json2unreal <input_json_file> -o <output_directory>
```

**Example:**
```bash
python3 json_to_unreal_converter.py json2unreal sample_story_cards.json -o UnrealOutput
```

This will generate:
- `UnrealOutput/UThomasJennings.h` - Header file
- `UnrealOutput/UThomasJennings.cpp` - Implementation file
- `UnrealOutput/UThomasJennings_BP.json` - Blueprint data
- ... (one set per entity in the JSON)

### Convert Unreal Engine Scripts to JSON

```bash
python3 json_to_unreal_converter.py unreal2json <unreal_directory> -o <output_json_file>
```

**Example:**
```bash
python3 json_to_unreal_converter.py unreal2json UnrealOutput -o reconstructed_story_cards.json
```

## JSON Structure

The converter expects JSON data organized by categories (Characters, Factions, Locations, etc.):

```json
{
    "Characters": {
        "CharacterName": {
            "name": "Character Name",
            "role": "Protagonist",
            "age": 30,
            "attributes": {
                "strength": 85,
                "intelligence": 90
            },
            "abilities": ["Hacking", "Combat"]
        }
    },
    "Locations": {
        "LocationName": {
            "name": "Secret Base",
            "type": "Military Facility",
            "coordinates": [45.0, -122.0]
        }
    }
}
```

## Generated Unreal Engine Code

### Header File Example (.h)

```cpp
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "UThomasJennings.generated.h"

/**
 * AI programmer at Chaotic Entertainment
 */
UCLASS(BlueprintType, Blueprintable)
class UThomasJennings : public UDataAsset
{
    GENERATED_BODY()

public:
    UThomasJennings();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    FString role;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
    int32 age;
};
```

### Implementation File Example (.cpp)

```cpp
#include "UThomasJennings.h"

UThomasJennings::UThomasJennings()
{
    name = TEXT("Thomas Jennings");
    role = TEXT("AI Programmer");
    age = 28;
}
```

### Blueprint JSON Example

```json
{
    "Type": "Blueprint",
    "Class": "UThomasJennings",
    "ParentClass": "/Script/Engine.DataAsset",
    "Properties": {
        "name": {
            "Type": "FString",
            "Value": "Thomas Jennings"
        },
        "role": {
            "Type": "FString",
            "Value": "AI Programmer"
        },
        "age": {
            "Type": "int32",
            "Value": 28
        }
    }
}
```

## Integration with Unreal Engine

### Step 1: Copy Generated Files

Copy the generated `.h` and `.cpp` files to your Unreal Engine project's `Source` directory:

```
YourProject/
├── Source/
│   ├── YourProject/
│   │   ├── UThomasJennings.h
│   │   ├── UThomasJennings.cpp
│   │   └── ...
```

### Step 2: Add to Build Configuration

Ensure your `.uproject` file includes the module, then regenerate project files:

```bash
# Right-click .uproject → Generate Visual Studio project files
```

### Step 3: Compile

Open the project in Unreal Engine or compile via IDE:

```bash
# Visual Studio: Build → Build Solution
# Or in Unreal Editor: Compile button
```

### Step 4: Create Blueprint Assets

1. In Unreal Editor, go to Content Browser
2. Right-click → Blueprint Class
3. Select your generated class (e.g., `UThomasJennings`)
4. Configure properties in the Blueprint editor

### Step 5: Use in Game Logic

```cpp
// C++ Usage
UThomasJennings* Character = NewObject<UThomasJennings>();
FString CharacterName = Character->name;
```

```cpp
// Blueprint: Drag the Data Asset into your level or reference in Blueprint graphs
```

## Advanced Features

### Custom Type Mapping

Modify the `get_unreal_type()` method in `UnrealScriptGenerator` to add custom type mappings:

```python
def get_unreal_type(self, value: Any) -> str:
    if isinstance(value, dict) and 'x' in value and 'y' in value:
        return "FVector2D"
    # ... existing mappings
```

### Adding Custom Properties

The converter automatically handles nested structures. For complex game-specific types:

```json
{
    "position": {"x": 100, "y": 200, "z": 50}
}
```

Will generate:
```cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Story Card")
FStoryCardData position;
```

### Batch Conversion

Convert multiple JSON files:

```bash
for file in *.json; do
    python3 json_to_unreal_converter.py json2unreal "$file" -o "UnrealOutput_${file%.json}"
done
```

## Troubleshooting

### Issue: "Invalid C++ identifier"

**Solution**: The converter automatically sanitizes names. If issues persist, check for:
- Names starting with numbers
- Special characters in property names
- Reserved C++ keywords

### Issue: "Type mismatch in Unreal Engine"

**Solution**: Verify the type mapping in `get_unreal_type()`. You may need to add custom mappings for your specific data structures.

### Issue: "Compilation errors in Unreal Engine"

**Solution**: 
1. Ensure all generated files are in the correct directory
2. Regenerate project files
3. Check for missing includes or forward declarations
4. Verify GENERATED_BODY() macro is present

## Best Practices

1. **Organize JSON by Category**: Group related entities (Characters, Locations, Items)
2. **Use Consistent Naming**: Follow PascalCase for entity names
3. **Document Descriptions**: Include description fields for better code documentation
4. **Version Control**: Keep both JSON and generated files in version control
5. **Incremental Updates**: Regenerate only changed entities to avoid merge conflicts

## Example Workflow

```bash
# 1. Create/edit your story cards
vim story_cards.json

# 2. Convert to Unreal Engine
python3 json_to_unreal_converter.py json2unreal story_cards.json -o MyGame/Source/MyGame/StoryCards

# 3. Compile in Unreal Engine
# (Open project and compile)

# 4. Make changes in Unreal Engine
# (Edit properties in Blueprint editor)

# 5. Export back to JSON (optional)
python3 json_to_unreal_converter.py unreal2json MyGame/Source/MyGame/StoryCards -o updated_story_cards.json
```

## Extending the Converter

### Add New Output Formats

Create a new generator class:

```python
class UnrealBlueprintGenerator:
    def generate_blueprint_xml(self, entity_data):
        # Generate native Blueprint XML format
        pass
```

### Add Validation

```python
def validate_json_structure(self, data: Dict) -> bool:
    required_fields = ['name', 'type']
    for field in required_fields:
        if field not in data:
            raise ValueError(f"Missing required field: {field}")
    return True
```

## License

This tool is provided as-is for converting story card data to Unreal Engine formats.

## Support

For issues or questions:
1. Check the troubleshooting section
2. Review generated code for syntax errors
3. Verify JSON structure matches expected format
4. Consult Unreal Engine documentation for integration issues

## Version History

- **1.0.0** (2025-11-16): Initial release
  - JSON to Unreal C++/Blueprint conversion
  - Unreal to JSON reverse conversion
  - Automatic type mapping
  - Name sanitization
