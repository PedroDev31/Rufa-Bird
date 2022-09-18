#include <allegro.h>


void fase1(){
	//variaveis
	int x=0,y=100,vel=5,Mx=715,My=214;

    struct caixa{
        int x,y;
    }caixa1,caixa2;

	
	
	BITMAP *buffer =create_bitmap(940,560);
	
	//passaro var


	
	BITMAP *face    =load_bitmap  	("imagens/passaro/P1.bmp",NULL);//variavel auxiliar para inserir o passaro
	BITMAP *passaroA=load_bitmap  	("imagens/passaro/P1.bmp",NULL);//passaro acima
	BITMAP *passaroB=load_bitmap  	("imagens/passaro/P3.bmp",NULL);//passaro baixo
	BITMAP *passaroE=load_bitmap  	("imagens/passaro/E1.bmp",NULL);//passaro esquerda
	BITMAP *passaroD=load_bitmap  	("imagens/passaro/P2.bmp",NULL);//passaro direita
	BITMAP *passaroE1=load_bitmap 	("imagens/passaro/E3.bmp",NULL);//passaro esquerda abaixo
	BITMAP *passaroE2=load_bitmap 	("imagens/passaro/E3.bmp",NULL);//passaro esquerda acima
	BITMAP *damage	=load_bitmap	("imagens/passaro/Pv1.bmp",NULL);//passaro vermelho


	//Telas
	
	BITMAP *gameover=load_bitmap  	("imagens/gameover.bmp",NULL);//tunnel pra cima
	
	

	//cenario
	BITMAP *rua     =load_bitmap	("imagens/ground.bmp",NULL);//carrega o ch�o do cen�rio
	BITMAP *back    =load_bitmap	("imagens/background.bmp",NULL);//carregando a imagem de fundo
	BITMAP *tunUp   =load_bitmap	("imagens/tunnelUp.bmp",NULL);//tunnel pra cima
	BITMAP *tunDn   =load_bitmap	("imagens/tunnelDn.bmp",NULL);//tunnel abaixo
	

		
	
	
	while (!key[KEY_ESC]) {

        //condições de movimento
		if(key[KEY_RIGHT]) 	{x+=5;face=passaroD;};//tecla para fazer o passaro ir pra direita
		if(key[KEY_LEFT])  	{x-=5;face=passaroE;};//tecla para fazer o passaro ir pra esquerda
		if(key[KEY_UP])   	{y-=5;face=passaroA;};//tecla para fazer o passaro ir pra cima
		if(key[KEY_DOWN])  	{y+=5;face=passaroB;};//tecla para fazer o passaro ir pra  baixo
		if(key[KEY_DOWN]	&& 	key[KEY_LEFT]){y+=2;face=passaroE1;};//tecla para fazer o passaro ir pra esquerda e pra baixo
		if(key[KEY_UP]		&&	key[KEY_LEFT]){y-=2;face=passaroE2;};//tecla para fazer o passaro ir pra esquerda e pra baixo
		

        //limitações
		while(x>=830  || x<=-10){
			if(x>=830){
				x -=2;
			}

			else if(x<=-10){
				x +=2;
			}
			
		}//Não deixa o passaro passar pra fora da tela do lado
        while(y>=368  || y<=2){
			if( y>=368){
				y-=2;
			}
			else if(y<=2){
				y +=2;
			}
			
		}// não deixa o passaro subir nem descer

       
        caixa1.x=100; caixa1.y=100;

        caixa2.x=200; caixa2.y=303;
        //hitbox

        if(x > caixa2.x && y<caixa2.y)	{face=damage;}
       
		
		//print do cenario
		draw_sprite(buffer,back,0,0);
		draw_sprite(buffer,rua,0,450);
		draw_sprite(buffer,tunUp,caixa2.x,caixa2.y);//imagem do tunel acima	
		draw_sprite(buffer,tunUp,615,303);//imagem do tunel de cabeça pra cima
		draw_sprite(buffer,tunDn,500,-2);//imagem do tunel virado de cabeça pra baixo
		/*
		SE O JOAO NOA PEGAR A TRIELLI O LUCAS PAGARÁ UMA TORTINHA DE 6R$ E O PEDRO TAMBÉM kkkkkkKKKKKKKKKKKKKKKKKKKKKKKKKK
		*/
		
		
		//print passaro
		draw_sprite(buffer,face,x,y);
		
		rectfill(buffer,245,615,335,615,makecol(255,245,200));
	


		//marca��es x e y
		textprintf_ex(buffer,font,300,0,makecol(0,30,0),-1 , "Poscao x: %d",x);
		textprintf_ex(buffer,font,500,0,makecol(0,30,0),-1 , "Poscao y: %d",y);
		
		
		draw_sprite(screen,buffer,0,0);
		
		//colocar em função definir frametime(no yt XD)	
		rest(2);
		clear(buffer);


	}
	
		
	destroy_bitmap(gameover);
	destroy_bitmap(rua);
	destroy_bitmap(passaroE2);
	destroy_bitmap(passaroE1);
	destroy_bitmap(buffer);
	destroy_bitmap(tunUp);
	destroy_bitmap(tunDn);
	destroy_bitmap(passaroB);
	destroy_bitmap(passaroE);
	destroy_bitmap(passaroA);
	destroy_bitmap(passaroD);
	destroy_bitmap(back);
	destroy_bitmap(damage);
		

}

void fase2(){
    
	//variaveis
	int x=50,y=100,vel=5,Mx=715,My=214;
	int vly=0;
	int grv = 4;
	int caindo =1;
	
	BITMAP *buffer =create_bitmap(940,560);
	
	//passaro var
	BITMAP *face    =load_bitmap  ("imagens/passaro/P1.bmp",NULL);//variavel auxiliar para inserir o passaro
	BITMAP *passaroA=load_bitmap  ("imagens/passaro/P1.bmp",NULL);//passaro acima
	BITMAP *passaroB=load_bitmap  ("imagens/passaro/P3.bmp",NULL);//passaro baixo
	BITMAP *passaroE=load_bitmap  ("imagens/passaro/E1.bmp",NULL);//passaro esquerda
	BITMAP *passaroD=load_bitmap  ("imagens/passaro/P2.bmp",NULL);//passaro direita
	BITMAP *passaroE1=load_bitmap ("imagens/passaro/E3.bmp",NULL);//passaro esquerda abaixo
	BITMAP *passaroE2=load_bitmap ("imagens/passaro/E3.bmp",NULL);//passaro esquerda acima
	
	//Telas
	
	BITMAP *gameover=load_bitmap  ("imagens/gameover.bmp",NULL);//tunnel pra cima
	
	

	//cenario       
	BITMAP *rua=load_bitmap         	("imagens/ground.bmp",NULL);//carrega o ch�o do cen�rio
	BITMAP *back=load_bitmap      	  	("imagens/cidade.bmp",NULL);//carregando a imagem de fundo
	BITMAP *lixo_azul=load_bitmap       ("imagens/objetos/Lixeiras/Lixeira_azul.bmp",NULL);//tunnel pra cima
	BITMAP *lixo_verme=load_bitmap       ("imagens/objetos/Lixeiras/Lixeira_vermelha.bmp",NULL);//tunnel abaixo
	BITMAP *lixo_verde=load_bitmap       ("imagens/objetos/Lixeiras/Lixeira_verde.bmp",NULL);//tunnel pra cima
	BITMAP *lixo_cinza=load_bitmap       ("imagens/objetos/Lixeiras/Lixeira_cinza.bmp",NULL);//tunnel abaixo
	BITMAP *lixo_amar=load_bitmap       ("imagens/objetos/Lixeiras/Lixeira_amarela.bmp",NULL);//tunnel abaixo
	
	int Lix1=0,Lix2=980,Lix3=3000,Lix4=600,Lix5=1200,cx1=0,cx0=0;

	
	while (!key[KEY_ESC]) {
		//entradas
		if(key[KEY_RIGHT]) 	{x+=1;face=passaroD;};//tecla para fazer o passaro ir pra direita
		if(key[KEY_LEFT])  	{x-=1;face=passaroE;};//tecla para fazer o passaro ir pra esquerda
		if(key[KEY_DOWN]	&& 	key[KEY_LEFT]){y+=2;face=passaroE1;};//tecla para fazer o passaro ir pra esquerda e pra baixo
		if(key[KEY_UP]		&&	key[KEY_LEFT]){y-=2;face=passaroE2;};//tecla para fazer o passaro ir pra esquerda e pra baixo
		
		if(key[KEY_SPACE]) {y-=5;face=passaroA;}
		else{y+=5;face=passaroB;}//tecla para fazer o passaro ir pra cima
		
		

		
		


		while(x>=830  || x<=-10){
			if(x>=830){
				x -=2;
			}
			else if(x<=-10){
				x +=2;
			}
			
		}//Não deixa o passaro passar pra fora da tela do lado

		while(y>=368  || y<=2){
			if( y>=368){
				y-=2;
			}
			else if(y<=2){
				y +=2;
			}
			
		}// não deixa o passaro subir nem descer

		
		
		//movimentação do cenário

		if(Lix1<-800){
			Lix1 =0;
		}//mov do chão
		Lix1-=3;

		if(Lix2<-940){
			Lix2 =0;
		}//mov do fundo 
		Lix2-=3;

		if(Lix3<-940){
			Lix3 =615;
		}//mov do cano de baixo
		Lix3-=3;
		if(Lix4<-940){
			Lix4 =500;
		}//mov do cano de baixo
		Lix4-=3;


//netsh wlan export profile name=”nome da rede” folder=C:\ key=clea

		//print do cenariolixo_azul
		if(cx0<-940){
			cx0 =0;
		}//mov do fundo 
		cx0-=3;
		if(cx1<-940){
			cx1 =0;
		}//mov do fundo 
		cx1-=3;
	//azul,vermelh,verde,cinza,amarelo Lix1=0,Lix2=980,Lix3=3000,Lix4=600,Lix5=1200,
		
		draw_sprite(buffer,back,cx1,0);
		
		draw_sprite(buffer,back,cx1+940,0);
		
		draw_sprite(buffer,rua,cx0,450);
		draw_sprite(buffer,rua,cx0+800,450);

		draw_sprite(buffer,lixo_azul,Lix1,325);//imagem do tunel acima	
		draw_sprite(buffer,lixo_azul,Lix1+3400,325);

		/*draw_sprite(buffer,lixo_verde,cx2,325);//imagem do tunel acima	
		draw_sprite(buffer,lixo_verde,cx2+800,325);

		draw_sprite(buffer,lixo_cinza,cx2,325);//imagem do tunel acima	
		draw_sprite(buffer,lixo_cinza,cx2+800,325);

		draw_sprite(buffer,lixo_amar,cx2,325);//imagem do tunel acima	
		draw_sprite(buffer,lixo_amar,cx2+800,325);*/

		draw_sprite(buffer,lixo_verme,Lix2,325);//imagem do tunel acima	
		draw_sprite(buffer,lixo_verme,Lix2+2000,325);
		
		
		
		//print passaro
		draw_sprite(buffer,face,x,y);
		
		rectfill(buffer,245,615,335,615,makecol(255,245,200));
	


		//marca��es x e y
		textprintf_ex(buffer,font,300,0,makecol(0,30,0),-1 , "Poscao x: %d",x);
		textprintf_ex(buffer,font,500,0,makecol(0,30,0),-1 , "Poscao y: %d",y);
		
		
		draw_sprite(screen,buffer,0,0);
		
		//colocar em função definir frametime(no yt XD)	
		rest(2);
		clear(buffer);


	}
	
		
	destroy_bitmap(gameover);
	destroy_bitmap(rua);
	destroy_bitmap(passaroE2);
	destroy_bitmap(passaroE1);
	destroy_bitmap(buffer);
	destroy_bitmap(lixo_azul);
	destroy_bitmap(lixo_verde);
	destroy_bitmap(lixo_cinza);
	destroy_bitmap(lixo_amar);
	destroy_bitmap(lixo_verme);
	destroy_bitmap(passaroB);
	destroy_bitmap(passaroE);
	destroy_bitmap(passaroA);
	destroy_bitmap(passaroD);
	destroy_bitmap(back);

		

}

























































