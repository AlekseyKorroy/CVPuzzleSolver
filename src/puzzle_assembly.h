#pragma once

#include <vector>
#include <ostream>

#include <libbase/point2.h>
#include <libimages/image.h>

struct MatchedSide final {
    int objB = -1;
    int sideB = -1;
    float differenceBest = -1.0f;
    float differenceSecondBest = -1.0f;
};

struct PlacedPiece final {
    int obj = -1;
    int rot90 = 0; // 0..3, clockwise
};

struct PuzzleAssemblyResult final {
    int W = 0;
    int H = 0;

    // Row-major grid: y*W + x
    std::vector<PlacedPiece> grid;

    // Column widths and row heights (in pixels of assembled canvas)
    std::vector<int> colW;
    std::vector<int> rowH;

    image8u assembled;           // 10_assembled.png
    image8u assembledWithLines;  // 09_assembled_with_lines.png
};

PuzzleAssemblyResult assemblePuzzle(
    const std::vector<image8u>& objImages,
    const std::vector<image8u>& objMasks,
    const std::vector<std::vector<point2i>>& objCorners, // size=objects_count, each size=4, order consistent with side indices
    const std::vector<std::vector<MatchedSide>>& objMatchedSides);

void printGrid(std::ostream& os, const PuzzleAssemblyResult& r);
