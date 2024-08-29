#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aColor;

out VS_OUT{
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
	vec3 Color;
} vs_out;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform bool shader;
uniform bool ifTex;
//uniform vec3 objectColor;

void main()
{
	vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
    // N' = WN, transpose(W)*M = I, W = transpose(inverse(M))
	if(shader) vs_out.Normal = mat3(transpose(inverse(model))) * aNormal;
	else vs_out.Normal = vec3(0.0,0.0,0.0);
	if(ifTex) {
		vs_out.TexCoords = aTexCoords;
	}
	gl_Position = projection * view * vec4(vs_out.FragPos, 1.0);
	vs_out.Color = vec3(aColor.x, aColor.y, aColor.z);
}