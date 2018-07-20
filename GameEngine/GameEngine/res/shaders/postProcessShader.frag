#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D terrain;
uniform sampler2D objects;
uniform sampler2D effects;

uniform float ui_trans;
uniform float ui_blue;
uniform vec4 ambientLight;

uniform vec4 screen_color;
uniform float screen_color_percent;

void main(){
	vec4 ui_color = texture(ui, uv);
	vec4 world_color = texture(terrain, uv);
	vec4 objects_color = texture(objects, uv);
	vec4 effects_color = texture(effects, uv);

	vec4 finalColor = vec4(0,0,0,1);
	finalColor = world_color;
	finalColor = mix(finalColor, objects_color, objects_color.a);

	
	
	vec4 totalLight = (ambientLight + effects_color);
	finalColor *= totalLight;
	
	
	finalColor = mix(finalColor, screen_color, screen_color_percent);
	
	
	vec4 uiColor = ui_color*ui_trans;
	finalColor = finalColor*(1-uiColor.a) + uiColor*(uiColor.a);
	//mix(finalColor, ui_color, .5);


	gl_FragColor = finalColor;
}
