#version 400 core

in vec2 uv;

uniform sampler2D image;

void main(){

/*
	vec4 t0 = texture(image, uv);
	vec4 t1 = texture(image, uv+vec2(0,0.005));
	vec4 t2 = texture(image, uv+vec2(0,-0.005));
	vec4 t3 = texture(image, uv+vec2(0.005,0));
	vec4 t4 = texture(image, uv+vec2(-0.005,0));

	gl_FragColor = t0;
	
	if(t0.a == 0 && (t1.a != 0 || t2.a != 0 || t3.a != 0 || t4.a != 0)){
		gl_FragColor = vec4(1,1,1,1);
	}
*/


	gl_FragColor = texture(image, uv);

}
