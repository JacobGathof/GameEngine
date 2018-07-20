#version 400 core

in vec2 uv;
in vec2 uv2;
in vec2 uv3;
in vec2 fragCoord;

uniform sampler2D skybox;
uniform sampler2D dispMap;

uniform sampler2D tileset;
uniform sampler2D terrain;

uniform sampler2D objects;

uniform float gameTime;

const int TILE_SET_DIM = 64;
const int TERRAIN_DIM = 64;

void main(){

	vec2 disp = texture(dispMap, fract(uv+vec2(gameTime/8, 0))).xy;
	
	disp = vec2(.5,.5) - disp;
	disp = disp/64;
	
	
	vec2 adjustedUV = fragCoord + vec2(1-uv.x, uv.y)/4;
	adjustedUV.x = 1-adjustedUV.x;
	vec4 color = texture(terrain, adjustedUV);

	vec2 splitUV = fract(adjustedUV*TERRAIN_DIM);

	vec2 newUV = round(color.rg*256)/256;
	vec4 terrainColor = texture(tileset, newUV+splitUV/TILE_SET_DIM);
	vec4 objectColor = texture(objects, uv3+disp);
	
	vec4 skyboxColor = texture(skybox, uv2+disp);
	skyboxColor = vec4(0,0,0,1);
	
	vec4 totalColor = terrainColor.a * vec4(terrainColor.xyz*(1-objectColor.a) + objectColor.xyz, 1);
	totalColor = totalColor + skyboxColor*totalColor.a;
	totalColor = totalColor * vec4(.25,.25,.75,1);
	
	
	
	gl_FragColor = totalColor;

}
