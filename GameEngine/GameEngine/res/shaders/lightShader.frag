#version 400 core


void main(){

	vec2 temp = gl_PointCoord - vec2(0.5, 0.5);
	float f = dot(temp, temp);

	int r = int(f < 0.25);

	vec4 color = vec4(1,1,1, r);

	gl_FragColor = color * vec4(1,1,1,1);

}
