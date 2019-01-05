#version 330 core
in vec3 vecColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 color;

uniform sampler2D Texture0;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;

void main()
{
	color = texture(Texture0, TexCoord); // * vec4(vecColor, 1.0);
	// TODO: uwzlêdnienie œwiat³a
}
