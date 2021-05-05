#version 330 core

layout (location = 0) in vec3 coordinate;
layout (location = 0) in vec3 normal;

out vec3 Normal;
out vec3 Obj;

uniform mat4 transformMat; 

void main()
{
	Obj = vec3(transformMat * vec4(coordinate, 1.0));
	gl_Position = transformMat * vec4(coordinate, 1.0);
	Normal = normalize(mat3(transpose(inverse(transformMat))) * normal);
}
