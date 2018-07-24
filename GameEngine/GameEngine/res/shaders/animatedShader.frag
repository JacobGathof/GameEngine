#version 400 core

in vec2 uv;
in vec2 sc;
in float depth;

uniform sampler2D image;
uniform int selected;

uniform vec4 color;

void main(){


	if(selected == 1){
		float k = (8.0 / 256) * (sc.x / 256);
		vec4 t0 = texture(image, uv);
		vec4 t1 = texture(image, uv+vec2(0,k));
		vec4 t2 = texture(image, uv+vec2(0,-k));
		vec4 t3 = texture(image, uv+vec2(k,0));
		vec4 t4 = texture(image, uv+vec2(-k,0));

		gl_FragColor = t0;
		
		if(t0.a == 0 && (t1.a != 0 || t2.a != 0 || t3.a != 0 || t4.a != 0)){
			gl_FragColor = vec4(1,1,1,1);
		}
		
	}else{
		gl_FragColor = texture(image, uv);
	}
	
	gl_FragDepth = depth;
	if(gl_FragColor.a <= 0.5){
		discard;
	}
	
	gl_FragColor *= color;
	
	//gl_FragColor = vec4(depth, depth, depth, 1);
	
	
}
