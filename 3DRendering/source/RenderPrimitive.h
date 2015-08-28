#ifndef RENDERPRIMITIVE_H
#define RENDERPRIMITIVE_H

class xdVector3i;



void DrawLineDDAScreenSpace(xdVector3i start, xdVector3i end, unsigned int color);
void DrawLineBresenhamScreenSpace(xdVector3i start, xdVector3i end, unsigned int color);





void DrawLineScreenSpace(xdVector3i start, xdVector3i end, unsigned int color);



void DrawTriangleScreenSpace(xdVector3i v1, xdVector3i v2, xdVector3i v3, unsigned int color);
void DrawTriangleScreenSpace1(xdVector3i top1, xdVector3i top2, xdVector3i bottom, unsigned int color);

void DrawTriangleScreenSpace2(xdVector3i bottom1, xdVector3i bottom2, xdVector3i top, unsigned int color); // Æ½µ×Èý½ÇÐÎ
#endif // !RENDERPRIMITIVE_H
