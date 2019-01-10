#version 330 core

in vec3 vecColor;
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture0;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform int showLight;

void main()
{	
	//ambient
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;
	
	//diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;
	
	//specular
	float specularStrength = 0.5f;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * lightColor;
	
	// light
	vec3 result = (ambient + diffuse + specular);
	if(showLight == 0)
	{
		result = vec3(1.0, 1.0, 1.0);
	}

	// (u, v) = (-0.1, -0.1) - "magic numbers" that mean "no texture, draw color"
	if(TexCoord.x != -0.1 && TexCoord.y != -0.1)
	{
		color = texture(Texture0, TexCoord) * vec4(result, 1.0);
	}
	else
	{
		color = vec4(result * vecColor, 1.0f);
	}
	
}
