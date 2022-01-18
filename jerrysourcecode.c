
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

static int jerriesC;
static int autoclickerC;
static int farmsC;
static int factoriesC;
static int facilitiesC;


FILE *save;
/* save data:
line 1: total currency(jerries)
line 2: Total autoclickers
line 3: Total farms
line 4: Total factories
line 5: total facilities
*/

void JerryClick(GtkWidget *buttonclicker, gpointer data)
{
  printf("clicked jerry");

}

int main(int argc, char ** argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window, *grid, *title, *buttonclicker, *autoclicker, *image;
  GtkWidget *jerrycount, *autoclickercount, *factory, *farm, *facility;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 280,200);
  gtk_window_set_title(GTK_WINDOW(window), "jerry clicker");
  gtk_window_set_resizable(GTK_WINDOW(window), 0);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  image = gtk_image_new_from_file("jerry.png");
  //gtk_image_set_pixel_size(image, 2.6);

  buttonclicker = gtk_button_new();
  gtk_button_set_image(GTK_BUTTON(buttonclicker), image);
  gtk_grid_attach(GTK_GRID(grid), buttonclicker, 1, 1, 1, 1);
  g_signal_connect(buttonclicker, "clicked", G_CALLBACK(JerryClick), NULL);

  autoclicker = gtk_button_new_with_label("Buy jerry clicker[10 J]");
  gtk_grid_attach(GTK_GRID(grid), autoclicker, 3,2,1,1);

  factory = gtk_button_new_with_label("Buy jerry factory[10000 J]");
  gtk_grid_attach(GTK_GRID(grid), factory, 3,3,1,1);

  farm = gtk_button_new_with_label("Buy jerry farm[200 J]");
  gtk_grid_attach(GTK_GRID(grid), farm, 1,2,1,1);

  facility = gtk_button_new_with_label("Buy jerry facility[1000 J]");
  gtk_grid_attach(GTK_GRID(grid), facility, 1,3,1,1);


  jerrycount = gtk_label_new("0 jerries\n0 autoclickers\n0 farms\n0 facilities\n0 factories");
  gtk_grid_attach(GTK_GRID(grid), jerrycount, 3, 1, 1, 1);

  int lines = 1;

  char readingline[100];
  save = fopen("save.dat", "r");
  while(lines <=5){
    fgets(readingline, 20, save);
    if (lines == 1){
      jerriesC = atoi(readingline);
    }else if(lines == 2){
      autoclickerC = atoi(readingline);
    }else if(lines == 3){
      farmsC = atoi(readingline);
    }else if(lines == 4){
      facilitiesC = atoi(readingline);
    }else{
      factoriesC = atoi(readingline);
    }

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    lines++;
  }
  fclose(save);


//  autoclickercount = gtk_label_new("0 autoclickers");
//  gtk_grid_attach(GTK_GRID(grid), autoclickercount, 3, 3, 1, 1);


  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);




  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

static int jerriesC;
static int autoclickerC;
static int farmsC;
static int factoriesC;
static int facilitiesC;


FILE *save;
/* save data:
line 1: total currency(jerries)
line 2: Total autoclickers
line 3: Total farms
line 4: Total factories
line 5: total facilities
*/

void JerryClick(GtkWidget *buttonclicker, gpointer data)
{
  printf("clicked jerry");

}

int main(int argc, char ** argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window, *grid, *title, *buttonclicker, *autoclicker, *image;
  GtkWidget *jerrycount, *autoclickercount, *factory, *farm, *facility;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 280,200);
  gtk_window_set_title(GTK_WINDOW(window), "jerry clicker");
  gtk_window_set_resizable(GTK_WINDOW(window), 0);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  image = gtk_image_new_from_file("jerry.png");
  //gtk_image_set_pixel_size(image, 2.6);

  buttonclicker = gtk_button_new();
  gtk_button_set_image(GTK_BUTTON(buttonclicker), image);
  gtk_grid_attach(GTK_GRID(grid), buttonclicker, 1, 1, 1, 1);
  g_signal_connect(buttonclicker, "clicked", G_CALLBACK(JerryClick), NULL);

  autoclicker = gtk_button_new_with_label("Buy jerry clicker[10 J]");
  gtk_grid_attach(GTK_GRID(grid), autoclicker, 3,2,1,1);

  factory = gtk_button_new_with_label("Buy jerry factory[10000 J]");
  gtk_grid_attach(GTK_GRID(grid), factory, 3,3,1,1);

  farm = gtk_button_new_with_label("Buy jerry farm[200 J]");
  gtk_grid_attach(GTK_GRID(grid), farm, 1,2,1,1);

  facility = gtk_button_new_with_label("Buy jerry facility[1000 J]");
  gtk_grid_attach(GTK_GRID(grid), facility, 1,3,1,1);


  jerrycount = gtk_label_new("0 jerries\n0 autoclickers\n0 farms\n0 facilities\n0 factories");
  gtk_grid_attach(GTK_GRID(grid), jerrycount, 3, 1, 1, 1);

  int lines = 1;

  char readingline[100];
  save = fopen("save.dat", "r");
  while(lines <=5){
    fgets(readingline, 20, save);
    if (lines == 1){
      jerriesC = atoi(readingline);
    }else if(lines == 2){
      autoclickerC = atoi(readingline);
    }else if(lines == 3){
      farmsC = atoi(readingline);
    }else if(lines == 4){
      facilitiesC = atoi(readingline);
    }else{
      factoriesC = atoi(readingline);
    }

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    lines++;
  }
  fclose(save);


//  autoclickercount = gtk_label_new("0 autoclickers");
//  gtk_grid_attach(GTK_GRID(grid), autoclickercount, 3, 3, 1, 1);


  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);




  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

static int jerriesC;
static int autoclickerC;
static int farmsC;
static int factoriesC;
static int facilitiesC;


FILE *save;
/* save data:
line 1: total currency(jerries)
line 2: Total autoclickers
line 3: Total farms
line 4: Total factories
line 5: total facilities
*/

void JerryClick(GtkWidget *buttonclicker, gpointer data)
{
  printf("clicked jerry");

}

int main(int argc, char ** argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window, *grid, *title, *buttonclicker, *autoclicker, *image;
  GtkWidget *jerrycount, *autoclickercount, *factory, *farm, *facility;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 280,200);
  gtk_window_set_title(GTK_WINDOW(window), "jerry clicker");
  gtk_window_set_resizable(GTK_WINDOW(window), 0);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  image = gtk_image_new_from_file("jerry.png");
  //gtk_image_set_pixel_size(image, 2.6);

  buttonclicker = gtk_button_new();
  gtk_button_set_image(GTK_BUTTON(buttonclicker), image);
  gtk_grid_attach(GTK_GRID(grid), buttonclicker, 1, 1, 1, 1);
  g_signal_connect(buttonclicker, "clicked", G_CALLBACK(JerryClick), NULL);

  autoclicker = gtk_button_new_with_label("Buy jerry clicker[10 J]");
  gtk_grid_attach(GTK_GRID(grid), autoclicker, 3,2,1,1);

  factory = gtk_button_new_with_label("Buy jerry factory[10000 J]");
  gtk_grid_attach(GTK_GRID(grid), factory, 3,3,1,1);

  farm = gtk_button_new_with_label("Buy jerry farm[200 J]");
  gtk_grid_attach(GTK_GRID(grid), farm, 1,2,1,1);

  facility = gtk_button_new_with_label("Buy jerry facility[1000 J]");
  gtk_grid_attach(GTK_GRID(grid), facility, 1,3,1,1);


  jerrycount = gtk_label_new("0 jerries\n0 autoclickers\n0 farms\n0 facilities\n0 factories");
  gtk_grid_attach(GTK_GRID(grid), jerrycount, 3, 1, 1, 1);

  int lines = 1;

  char readingline[100];
  save = fopen("save.dat", "r");
  while(lines <=5){
    fgets(readingline, 20, save);
    if (lines == 1){
      jerriesC = atoi(readingline);
    }else if(lines == 2){
      autoclickerC = atoi(readingline);
    }else if(lines == 3){
      farmsC = atoi(readingline);
    }else if(lines == 4){
      facilitiesC = atoi(readingline);
    }else{
      factoriesC = atoi(readingline);
    }

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    lines++;
  }
  fclose(save);


//  autoclickercount = gtk_label_new("0 autoclickers");
//  gtk_grid_attach(GTK_GRID(grid), autoclickercount, 3, 3, 1, 1);


  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);




  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

static int jerriesC;
static int autoclickerC;
static int farmsC;
static int factoriesC;
static int facilitiesC;


FILE *save;
/* save data:
line 1: total currency(jerries)
line 2: Total autoclickers
line 3: Total farms
line 4: Total factories
line 5: total facilities
*/

void JerryClick(GtkWidget *buttonclicker, gpointer data)
{
  printf("clicked jerry");

}

int main(int argc, char ** argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window, *grid, *title, *buttonclicker, *autoclicker, *image;
  GtkWidget *jerrycount, *autoclickercount, *factory, *farm, *facility;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_default_size(GTK_WINDOW(window), 280,200);
  gtk_window_set_title(GTK_WINDOW(window), "jerry clicker");
  gtk_window_set_resizable(GTK_WINDOW(window), 0);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  image = gtk_image_new_from_file("jerry.png");
  //gtk_image_set_pixel_size(image, 2.6);

  buttonclicker = gtk_button_new();
  gtk_button_set_image(GTK_BUTTON(buttonclicker), image);
  gtk_grid_attach(GTK_GRID(grid), buttonclicker, 1, 1, 1, 1);
  g_signal_connect(buttonclicker, "clicked", G_CALLBACK(JerryClick), NULL);

  autoclicker = gtk_button_new_with_label("Buy jerry clicker[10 J]");
  gtk_grid_attach(GTK_GRID(grid), autoclicker, 3,2,1,1);

  factory = gtk_button_new_with_label("Buy jerry factory[10000 J]");
  gtk_grid_attach(GTK_GRID(grid), factory, 3,3,1,1);

  farm = gtk_button_new_with_label("Buy jerry farm[200 J]");
  gtk_grid_attach(GTK_GRID(grid), farm, 1,2,1,1);

  facility = gtk_button_new_with_label("Buy jerry facility[1000 J]");
  gtk_grid_attach(GTK_GRID(grid), facility, 1,3,1,1);


  jerrycount = gtk_label_new("0 jerries\n0 autoclickers\n0 farms\n0 facilities\n0 factories");
  gtk_grid_attach(GTK_GRID(grid), jerrycount, 3, 1, 1, 1);

  int lines = 1;

  char readingline[100];
  save = fopen("save.dat", "r");
  while(lines <=5){
    fgets(readingline, 20, save);
    if (lines == 1){
      jerriesC = atoi(readingline);
    }else if(lines == 2){
      autoclickerC = atoi(readingline);
    }else if(lines == 3){
      farmsC = atoi(readingline);
    }else if(lines == 4){
      facilitiesC = atoi(readingline);
    }else{
      factoriesC = atoi(readingline);
    }

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    lines++;
  }
  fclose(save);


//  autoclickercount = gtk_label_new("0 autoclickers");
//  gtk_grid_attach(GTK_GRID(grid), autoclickercount, 3, 3, 1, 1);


  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);




  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
