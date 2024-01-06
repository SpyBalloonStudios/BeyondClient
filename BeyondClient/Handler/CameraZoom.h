#pragma once

class CameraZoom
{
public:
	static float ZoomSpeed;

	void ZoomOut()
	{
		ZoomSpeed += 0.1f;
	}
	void ZoomIn()
	{
		ZoomSpeed -= 0.1f;
	}

	CameraZoom()
	{
		ZoomSpeed = 1.0f;
	}
};