#version 400 core

in vec4 col;
in float li;

void main(){

	const vec4 black = vec4(0,0,0,0);

	vec2 temp = gl_PointCoord - vec2(0.5);
	float f = dot(temp, temp);

	if(f > .25)
		discard;

	vec4 color = mix(col, black, .1f*f);

	gl_FragColor = color * vec4(1,1,1,li/4.0);

}
