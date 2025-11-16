#!/bin/bash
# Quick Start Guide for JSON to Unreal Engine Converter

echo "=========================================="
echo "JSON to Unreal Engine Converter"
echo "Quick Start Guide"
echo "=========================================="
echo ""

# Check if Python 3 is available
if ! command -v python3 &> /dev/null; then
    echo "❌ Python 3 is not installed. Please install Python 3.7 or higher."
    exit 1
fi

echo "✓ Python 3 is available"
echo ""

# Show available commands
echo "Available Commands:"
echo ""
echo "1. Convert JSON to Unreal Engine:"
echo "   python3 json_to_unreal_converter.py json2unreal <input.json> -o <output_dir>"
echo ""
echo "2. Convert Unreal Engine to JSON:"
echo "   python3 json_to_unreal_converter.py unreal2json <unreal_dir> -o <output.json>"
echo ""
echo "3. Run tests:"
echo "   python3 test_converter.py"
echo ""

# Check for sample file
if [ -f "sample_story_cards.json" ]; then
    echo "✓ Sample story cards file found: sample_story_cards.json"
    echo ""
    echo "Try it now:"
    echo "  python3 json_to_unreal_converter.py json2unreal sample_story_cards.json -o MyUnrealOutput"
    echo ""
fi

# Check if user provided a JSON file
if [ $# -eq 1 ]; then
    INPUT_FILE="$1"
    if [ -f "$INPUT_FILE" ]; then
        echo "Converting your file: $INPUT_FILE"
        OUTPUT_DIR="${INPUT_FILE%.json}_UnrealOutput"
        python3 json_to_unreal_converter.py json2unreal "$INPUT_FILE" -o "$OUTPUT_DIR"
        echo ""
        echo "✓ Conversion complete! Check the $OUTPUT_DIR directory."
    else
        echo "❌ File not found: $INPUT_FILE"
        exit 1
    fi
fi

echo ""
echo "For detailed documentation, see: CONVERTER_README.md"
echo "=========================================="
