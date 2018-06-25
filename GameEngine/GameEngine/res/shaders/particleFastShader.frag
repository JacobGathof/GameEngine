#version 400 core

in float alpha;
in vec3 color;

void main(){

	gl_FragColor = vec4(color,alpha);
}