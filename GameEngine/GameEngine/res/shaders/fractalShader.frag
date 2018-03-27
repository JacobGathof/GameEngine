#version 400 core

in vec2 coord;

const int maxit = 100;

void main(){

	int iteration = 0;
	float x = 0;
	float y = 0;
	float x0 = coord.x;
	float y0 = coord.y;

	while(x*x + y*y < 4 && iteration < maxit){
		float xtemp = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = xtemp;
		iteration = iteration + 1;
	}

	float val = (1.0f*iteration/maxit);
	if(iteration >= 100){
		val = 0;
	}

	vec4 col = vec4(0,0, val, 1);

	gl_FragColor = col;

}
