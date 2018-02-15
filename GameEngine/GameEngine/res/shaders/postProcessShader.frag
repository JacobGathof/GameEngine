#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D part;

void main(){
	gl_FragColor = texture(ui, uv) * vec4(1,1,1,.25);
	gl_FragColor += texture(part, uv) * vec4(1,1,1,.75);
}
