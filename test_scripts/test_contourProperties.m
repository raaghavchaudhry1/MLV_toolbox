LD1 = LD(1);

clear vecLD
vecLD.numContours = LD1.numLines;
vecLD.contours = LD1.lines;

resultLD = computeContourProperties(vecLD)
