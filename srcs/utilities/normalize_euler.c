#include "minirt.h"

t_euler	normalize_euler(t_euler euler)
{
	while (euler.yaw < -180)
		euler.yaw += 360;
	while (euler.yaw > 180)
		euler.yaw -= 360;
	while (euler.pitch < -180)
		euler.pitch += 360;
	while (euler.pitch > 180)
		euler.pitch -= 360;
	euler.roll = 0;
	return (euler);
}
