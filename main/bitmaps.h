BITMAP *buffer =create_bitmap(970,546);
	
	
	//passaro var
	BITMAP *face    =load_bitmap  ("imagens/P1.bmp",NULL);//variavel auxiliar para inserir o passaro
	BITMAP *passaroA=load_bitmap  ("imagens/P1.bmp",NULL);//passaro acima
	BITMAP *passaroB=load_bitmap  ("imagens/P3.bmp",NULL);//passaro baixo
	BITMAP *passaroE=load_bitmap  ("imagens/E1.bmp",NULL);//passaro esquerda
	BITMAP *passaroD=load_bitmap  ("imagens/P2.bmp",NULL);//passaro direita
	
	BITMAP *passaroE1=load_bitmap ("imagens/E3.bmp",NULL);//passaro esquerda abaixo
	BITMAP *passaroE2=load_bitmap ("imagens/E3.bmp",NULL);//passaro esquerda acima
	
	
	BITMAP *tunUp=load_bitmap  ("imagens/tunnelUp.bmp",NULL);//tunnel pra cima
	BITMAP *tunDn=load_bitmap  ("imagens/tunnelDn.bmp",NULL);//tunnel abaixo
	
	//cenario
	BITMAP *rua=load_bitmap      ("imagens/ground.bmp",NULL);//carrega o chão do cenário
	
	BITMAP *back=load_bitmap     ("imagens/background.bmp",NULL);//carregando a imagem de fundo

