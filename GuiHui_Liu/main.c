#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  int row, col;
  int i, j;
  struct matrix * m;
  struct matrix * point;
  struct matrix * n;
  screen s;
  color c;
  m = new_matrix(5,5);
  for(row = 0; row<m->rows; row++){
    for(col = 0; col<m->cols; col++){
      m->m[row][col] = row;
    }
  }
  n = new_matrix(5,5);
  for(row = 0; row<n->rows; row++){
    for(col = 0; col<n->cols; col++){
      n->m[row][col] = row;
    }
  }
  printf("Print original second matrix\n");
  print_matrix(n);
  matrix_mult(m,n);
  printf("multiplied matrix\n");
  print_matrix(n);
  printf("orignal first matrix\n");
  print_matrix(m);
  scalar_mult(5.0,m);
  printf("first matrix after scalar multiplication\n");
  print_matrix(m);
  ident(m);
  printf("first matrix after iden function\n");
  print_matrix(m);
  point = new_matrix(3,5);
  printf("original point matrix\n");
  print_matrix(point);
  printf("print point matrix after add point is call\n");
  print_matrix(point);
  //add_edge(point,0,0,0,350,500,0);
  printf("print point matrix after add edge is call\n");
  print_matrix(point);
  //large star
  add_point(point,0,0,0);
  add_point(point,250,500,0);
  add_edge(point,250,500,0,500,0,0);
  add_edge(point,0,350,0,500,0,0);
  add_edge(point,0,350,0,500,350,0);
  add_edge(point,0,0,0,500,350,0);
  //medium star
  add_edge(point,175,350,0,250,175,0);
  add_edge(point,250,175,0,325,350,0);
  add_edge(point,325,350,0,130,260,0);
  add_edge(point,130,260,0,370,260,0);
  add_edge(point,370,260,0,175,350,0);
  //small star
  add_edge(point,250,315,0,212,260,0);
  add_edge(point,250,315,0,288,260,0);
  add_edge(point,288,260,0,200,293,0);
  add_edge(point,200,293,0,300,293,0);
  add_edge(point,300,293,0,212,260,0);



  c.red = 122;
  c.green = 218;
  c.blue = 225;
  clear_screen(s);

  for( i=0; i<XRES; i++){
    for ( j=0; j<YRES; j++){

      //c.red = random() % (MAX_COLOR + 1);
      //c.green = random() % (MAX_COLOR + 1);
      //c.blue = random() % (MAX_COLOR + 1);
      plot( s, c, i, j);
    }
  }
  c.green = 40;
  draw_lines(point,s,c);

  display( s );    
  save_ppm(s,  "image" );
  save_extension(s, "image.png");
  free(m);
  free(n);
  free(point);
  
}  
