/*
随机产生半径，随机产生角度，极坐标
*/
class Solution {
public:
	Solution(double radius, double x_center, double y_center) {
		this->radius = radius;
		this->x_center = x_center;
		this->y_center = y_center;
		srand((int)time(0));
	}
	vector<double> randPoint() {
		vector<double> result;
		double r = 0.0;
		double theta = 0.0;
		double x = 0.0, y = 0.0;
		r = radius * sqrt((rand() % 1000000) / 1000001.0);
		theta = 360.0*((rand() % 1000000) / 1000001.0);
		x = r * sin(theta);
		y = r * cos(theta);
		result.push_back(x + x_center);
		result.push_back(y + y_center);
		return result;
	}
private:
	double radius;
	double x_center;
	double y_center;
};