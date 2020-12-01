#pragma once

#include <string>
#include <optional>
#include <vector>

#include "Engine.h"
#include "Body.h"
#include "Person.h"


class MotorVehicle {
public:
	MotorVehicle(Engine engine, Body body, Person owner, float const* tireDiameters, int numberOfTires);
	~MotorVehicle();

	void print() const;

	// Easy solution for classes doing manual memory management
	MotorVehicle(const MotorVehicle& other) = delete;
	MotorVehicle& operator=(const MotorVehicle& other) = delete;

private:
	Engine engine;
	Body body;
	Person owner;
	float* tireDiameters = nullptr;
	int numberOfTires = 0;

};


std::optional<MotorVehicle> motorVehicleFromStdio();






