#version 400 core

in vec4 col;
in float li;

void main(){

	const vec4 black = vec4(0,0,0,0);

	vec2 temp = gl_PointCoord - vec2(0.5);
	float f = dot(temp, temp);

	float r = 1.0 / (1 + 4*f + 64*f*f);
	vec4 color = vec4(1,1,1,r);

	gl_FragColor = color * col* vec4(1,1,1,abs(cos(li)));

}
