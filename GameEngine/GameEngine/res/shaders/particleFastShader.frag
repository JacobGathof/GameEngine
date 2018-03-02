#version 400 core

in float alpha;

void main(){

	gl_FragColor = vec4((1+alpha)/2,(1+alpha)/2,1,(1+alpha)/4);
}