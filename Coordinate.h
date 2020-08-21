#ifndef COORDINATE_H
#define COORDINATE_H

namespace coordinate 
{

	struct Coordinate 
	{
		double x;
		double y;
		Coordinate(double a = 0, double b = 0) {
			x = a;
			y = b;
		}
		friend bool operator==(const Coordinate& C1, const Coordinate& C2) {
			if ((C1.x == C2.x) && (C1.y == C2.y)) {
				return true;
			}
			else {
				return false;
			}
		}
	};

}

#endif
