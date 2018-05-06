#version 400 core

in vec2 uv;
in vec2 fragCoord;

uniform sampler2D tileset;
uniform sampler2D terrain;

const int TILE_SET_DIM = 64;
const int TERRAIN_DIM = 64;

void main(){

	vec2 adjustedUV = (.5*fragCoord + vec2(1-uv.x, uv.y))/4;
	adjustedUV.x = 1-adjustedUV.x;
	vec4 color = texture(terrain, adjustedUV);

	vec2 splitUV = fract(adjustedUV*TERRAIN_DIM);

	vec2 newUV = round(color.rg*256)/256;
	vec4 terrainColor = texture(tileset, newUV+splitUV/TILE_SET_DIM);


	gl_FragColor = terrainColor;

}
