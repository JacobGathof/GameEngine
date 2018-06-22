#version 400 core

uniform vec4 color;

in vec2 fragPos;

const float maxStrength = .25;
const float attenuation = 16;

uniform float gameTime;

float rand(){
	return ((cos(gameTime*2) + 1)/2) + 1; 
}

void main(){

	vec2 temp = fragPos;
	float d = dot(temp,temp);
	float f = clamp(1 - d, 0, 1);

	float alpha = maxStrength - maxStrength / (1 + attenuation*f*f);
	
	gl_FragColor = color * vec4(1,1,1,alpha);

}
