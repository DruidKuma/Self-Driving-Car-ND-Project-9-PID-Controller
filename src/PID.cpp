#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

    // init gains
	this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    // init errors
    i_error = 0.0;
    d_error = 0.0;
    p_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    i_error = i_error + cte;
    p_error = cte;
}

double PID::TotalError() {
	return -(Kp * p_error + Ki * i_error + Kd * d_error);
}

