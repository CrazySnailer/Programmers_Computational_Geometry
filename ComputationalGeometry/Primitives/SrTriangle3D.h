/************************************************************************		
\link	www.twinklingstar.cn
\author Twinkling Star
\date	2013/12/14
****************************************************************************/
#ifndef SR_PRIMITIVE_TRIANGLE3D_H
#define SR_PRIMITIVE_TRIANGLE3D_H

/** \addtogroup primitive
  @{
*/
#include "SrPrimitive.h"

/**
\brief 3D triangle class.
This is a 3D triangle class with public data members.
*/

class SrTriangle3D
{
public:
	/**
	\brief Default constructor, endpoints is set to (0,0).
	*/
	SrTriangle3D();
	/**
	\brief The line is initialized by three points.
	*/
	SrTriangle3D(const SrPoint3D&,const SrPoint3D&,const SrPoint3D&);
	/**
	\brief Destructor. Do nothing.
	*/
	~SrTriangle3D();
	/**
	\brief  Compute the distance from the point to the triangle.
	*/
	SrReal	toPointDistance(const SrPoint3D&) const;
	/**
	\brief The triangle is valid if the three points are not on a line.
	*/
	bool	isValid() const;
	/**
	\brief  Compute the normal using Newell method devised by Martin Newell.It relates to the order of the points.
	*/
	const SrVector3D normal()const;
	/**
	\brief  Compute the area.
	*/
	SrReal	area() const;
	/**
	\brief  Judge whether the point is in the triangle or not.
	\return SR_POSITION_ON		 if the point is on the edge; 
			SR_POSITION_INSIDE  if inside the triangle and on the same plane; 
			SR_POSITION_OUTSIDE if outside the triangle and on the same plane.
			SR_POSITION_INVALID if not on the same plane.
	*/
	int		pointLocation(const SrPoint3D&) const;
	/**
	\brief  Compute the perimeter.
	*/
	SrReal	perimeter() const;
	/**
	\brief Rotate the triangle through an angle about a coordinate axis.
		
		For an x-roll,the y-axis rotates to the z-axis.
		For a y-roll,the z-axis rotates to the x-axis.
		For a z-roll,the x-axis rotates to the y-axis.
	*/
	void rotateX(SrReal);
	void rotateY(SrReal);
	void rotateZ(SrReal);
	/**
	\brief  Translate the triangle.
	*/
	void translate(const SrVector3D&);
	/**
	\brief  Judge whether or not the line hits the triangle.
	\return SR_OVERLAPPING		if the line is on the plane where the triangle lies;
			SR_PARALLEL			if the line is parallel to the triangle.
			SR_DISJOINT			if the line misses the triangle;
			SR_INTERSECTING		if the line intersects with the triangle and intersection point is not on the edge.
	\param[out] result If the line intersects with the triangle and the intersection point information is put in 'result'.
	*/
	int lineHitTest(const SrLine3D&,SrPoint3D& /*[OUT]*/ result)const;
	/**
	\brief  Judge whether or not the ray hits the triangle.
	\return SR_OVERLAPPING		if the ray is on the plane where the triangle lies;
			SR_PARALLEL			if the ray is parallel to the triangle.
			SR_DISJOINT			if the ray misses the triangle;
			SR_INTERSECTING		if the ray intersects with the triangle and intersection point is not on the edge.
	\param[out] result If the ray intersects with the triangle and the intersection point information is put in 'result'.
	*/
	int rayHitTest(const SrRay3D&,SrPoint3D& /*[OUT]*/ result)const;
	/**
	\brief  Judge whether or not the segment hits the triangle.
	\return SR_OVERLAPPING		 if the segment is on the plane where the triangle lies;
			SR_PARALLEL			 if the segment is parallel to the triangle.
			SR_DISJOINT			 if the segment misses the triangle;
			SR_INTERSECTING		 if the segment intersects with the triangle and intersection point is not on the edge.
	\param[out] result If the segment intersects with the triangle and the intersection point information is put in 'result'.
	*/
	int segmentHitTest(const SrSegment3D&,SrPoint3D& /*[OUT]*/ result)const;


public:
	SrPoint3D	mPoint[3];

private:
	/**
	\brief  Judge whether or not the line hits the triangle.The line is base + t*direction. 
			It is not necessary for direction to be unit length.
	\return SR_OVERLAPPING		 if the line is on the plane where the triangle lies;
			SR_PARALLEL			 if the line is parallel to the triangle.
			SR_DISJOINT			 if the line misses the triangle;
			SR_INTERSECTING		 if the line intersects with the triangle.
	\param[out] result return the result of (u,v,t) if the line intersects with the triangle.
	*/
	int		linearIntersectTriangle(const SrPoint3D& base,const SrVector3D& direction,SrVector3D& info)const;

	void	computeInterval(const SrTriangle3D& ,const SrVector3D& ,int ,SrReal*,SrReal*)const;
	int		triangle3dCoplanarTriangle3d(const SrTriangle3D& ,const SrTriangle3D& ,int )const;
};

/** @} */
#endif