LD1 = LD(1);


vecLD.numContours = LD1.numLines;
vecLD.contours = LD1.lines;

% vecLD = computeJunctions(vecLD);
vecLD = computeContourProperties(vecLD);
vecLD = computeCurvature(vecLD);