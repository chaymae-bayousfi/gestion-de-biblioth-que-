# Variables de compilation
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Dossier contenant les sources
SRC_DIR = src

# Fichiers sources
SRC = main.cpp \
      gestion_utilisateur/GestionUtilisateur.cpp \
      gestion_livre/GestionLivre.cpp \
      gestion_emprunt/GestionEmprunt.cpp \
      gestion_categorie/Gestion_Categorie.cpp \
      gestion_utilisateur/utilisateur.cpp \
      gestion_livre/livre.cpp \
      gestion_emprunt/emprunt.cpp \
      gestion_categorie/categorie.cpp

# Fichiers objets
OBJS = $(SRC:.cpp=.o)

# Nom de l'exécutable
NAME = gestion_bibliotheque

# Commande pour supprimer les fichiers temporaires
RM = rm -f

# Règle par défaut (compilation et génération de l'exécutable)
all: $(NAME)

# Lier les objets pour créer l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Règle pour compiler chaque fichier .cpp en fichier .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Supprimer les fichiers objets générés
clean:
	$(RM) $(OBJS)

# Supprimer les fichiers objets et l'exécutable
fclean: clean
	$(RM) $(NAME)

# Recompiler entièrement (supprime les fichiers intermédiaires et recrée l'exécutable)
re: fclean all

# Indiquer que ces cibles ne sont pas des fichiers
.PHONY: clean fclean re
