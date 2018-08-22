#version 400 core

in vec2 uv;
in vec2 fragPos;
in vec2 sc;
in float ep;

uniform sampler2D image;

void main(){

	vec2 d = fragPos/sc;
	float e = dot(d,d);
	uint a = uint(e < 1 && e > 1- ep);
	
	if(a < .5)
		discard;
	
	vec4 color = texture(image, gl_FragCoord.xy+vec2(.05, .05));
	gl_FragColor = vec4(color.rgba);
	
}