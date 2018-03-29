#version 400 core

in vec4 col;
in float li;
flat in uint circle;

void main(){

	vec2 temp = gl_PointCoord - vec2(0.5, 0.5);
	float f = dot(temp, temp);

	float r = f < 0.25 && f > .20 ? 1 : 0;

	if(circle == 0){
		r = 1;
	}
	vec4 color = vec4(1,1,1, r);

	gl_FragColor = color * col* vec4(1,1,1,li/3.0f);

}
