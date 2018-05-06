#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D world;
uniform sampler2D particles;
uniform sampler2D lights;

uniform float ui_trans;
uniform float ui_blue;

uniform vec4 screen_color;
uniform float screen_color_percent;

void main(){
	vec4 ui_color = texture(ui, uv);
	vec4 world_color = texture(world, uv);
	vec4 particles_color = texture(particles, uv);
	vec4 lights_color = texture(lights, uv);

	vec4 finalColor = vec4(0,0,0,1);
	finalColor = world_color;

	vec4 totalLight = ( vec4(.22,.33,.46,0) + lights_color);

	//finalColor = finalColor * vec4(.55,.45,.40,1);
	//finalColor = finalColor * totalLight;

	finalColor = mix(finalColor, screen_color, screen_color_percent);

	finalColor = finalColor + particles_color;

	vec4 uiColor = ui_color*ui_trans;
	finalColor = finalColor*(1-uiColor.a) + uiColor;
	//mix(finalColor, ui_color, .5);


	gl_FragColor = finalColor;
}
