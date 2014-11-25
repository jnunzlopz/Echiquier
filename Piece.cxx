/** 
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Piece.h"

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
 // cout << "Constructeur Piece" << endl;
}

Piece::~Piece()
{
  //cout << "Destructeur Piece" << endl;
}

Piece::Piece(const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  //cout << "Constructeur Piece par copie" << endl;
}

Piece &
Piece::operator=(const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  //cout << "Affectation Piece" << endl;
  return *this;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  //cout << "Constructeur Piece specialise" << endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x()
{
  return m_x;
}

int
Piece::y()
{
  return m_y;
}

bool
Piece::isWhite()
{
  return m_white;
}

bool
Piece::isBlack()
{
  return !m_white;
}

void
Piece::affiche()
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "B" : "N" ) << endl;
}

Piece
Piece::plusforte(const Piece & p) const
{
  cout << "plusforte" << endl;
  if (true) return p;
  return *this;
}

bool
Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Piece" << endl;
  return false;
}

char
Piece::myCode()
{
  return (m_white)?'B':'N';
}

Roi::Roi(bool white) : Piece(5,(white)?1:8,white)
{
  //cout << "Constructeur Roi" << endl;
}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Roi" << endl;
  return false;
}

char
Roi::myCode()
{
  return (m_white)?'R':'r';
}

Tour::Tour(bool white,bool left) : Piece((left)?1:8,(white)?1:8,white)
{
 // cout << "Constructeur Tour" << endl;
}

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Tour" << endl;
  return false;
}

char
Tour::myCode()
{
  return (m_white)?'T':'t';
}

Fou::Fou(bool white,bool left) : Piece((left)?3:6,(white)?1:8,white)
{
  //cout << "Constructeur Fou" << endl;
}

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Fou" << endl;
  return false;
}

char
Fou::myCode()
{
  return (m_white)?'F':'f';
}

Reine::Reine(bool white) : Piece(4,(white)?1:8,white), Tour(white,true), Fou(white,true)
{
  //cout << "Constructeur Reine" << endl;
}

bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "Mouvement Valide Reine" << endl;
  return Tour::mouvementValide(e,x,y) || Fou::mouvementValide(e,x,y);
}

char
Reine::myCode()
{
  return (m_white)?'Q':'q';
}

Cavalier::Cavalier(bool white, bool left) : Piece((left)?2:7,(white)?1:8,white), Tour(white,left)
{
	//cout << "Constructeur Cavalier" << endl;
}

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
	 cout << "Mouvement Valide Cavalier" << endl;
	 return true;
}

char
Cavalier::myCode()
{
  return (m_white)?'C':'c';
}