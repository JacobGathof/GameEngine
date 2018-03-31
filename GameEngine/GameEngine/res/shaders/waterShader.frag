#version 400 core

in vec2 uv;
in vec2 uv2;

uniform sampler2D skybox;
uniform sampler2D world;
uniform sampler2D dispMap;

uniform float gameTime;

void main(){

	vec2 disp = texture(dispMap, fract(uv+vec2(gameTime/8, 0))).xy/64;

	vec4 color = texture(world, uv2+disp);
	//color = color + texture(skybox, uv+disp);
	color = color * vec4(.25,.25,.75,1);

	gl_FragColor = color;

}
