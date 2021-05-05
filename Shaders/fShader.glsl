#version 330 core

in vec3 Normal;
in vec3 Obj;

out vec4 FragColor;

uniform vec3 lightSource;
uniform vec3 color;

void main()
{
	vec3 lightRay = normalize(lightSource - Obj);
	float diffStr = max(dot(Normal, lightRay), 0.0);
	vec3 diffusedLgt = diffStr * vec3(1, 1, 1);

	float ambientStr = 0.5;
	vec3 ambientLgt = ambientStr * vec3(1, 1, 1);

	vec3 color = (ambientLgt + diffusedLgt) * color;
	FragColor = vec4(color, 1.0);
}