uniform sampler2D texture;
void main(){
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	float gray = pixel.r*0.2989 + pixel.g*0.5870 + pixel.b*0.1140;
	gl_FragColor = vec4(gray,gray,gray,pixel.a);
}