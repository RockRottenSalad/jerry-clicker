
#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
#include<unistd.h>

static int jerriesC;
static int autoclickerC;
static int farmsC;
static int factoriesC;
static int facilitiesC;

static int priceAuto;
static int priceFarm;
static int priceFacility;
static int priceFactory;

static GtkWidget *jerrycount;


FILE *save;
/* save data:
line 1: total currency(jerries)
line 2: Total autoclickers
line 3: Total farms
line 4: Total factories
line 5: total facilities
*/


static int lines = 1;

void SaveData(){

  save = fopen("save.dat", "w");
  fclose(save);

  save = fopen("save.dat", "a");

  fprintf(save, "%d\n", jerriesC);
  fprintf(save, "%d\n", autoclickerC);
  fprintf(save, "%d\n", farmsC);
  fprintf(save, "%d\n", facilitiesC);
  fprintf(save, "%d", factoriesC);

  fclose(save);

}



void Win(GtkWidget *buttonclicker){
  if (jerriesC >= 2000000000){;
    char readingline[] = "YOU WON\ncongratulations on\n wasiting ur time";
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);
  jerriesC = jerriesC-2000000000;
  }
}

void AutoClickerBuy(GtkWidget *autoclicker){
  if(jerriesC >= priceAuto){
    jerriesC = jerriesC - priceAuto;
    autoclickerC++;
    char readingline[100];

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    int pricemult = autoclickerC/10;
    pricemult = pricemult+1;
    priceAuto = 10 * pricemult;
    char stringprice[32];
    snprintf(stringprice, sizeof(stringprice), "Buy jerry clicker[%d J]", priceAuto);
    gtk_button_set_label(GTK_BUTTON(autoclicker), stringprice);

  }
}

void FarmBuy(GtkWidget *farm){
  if(jerriesC >= priceFarm){
    jerriesC = jerriesC - priceFarm;
    farmsC++;
    char readingline[100];

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    int pricemult = farmsC/10;
    pricemult = pricemult+1;
    priceFarm = 200 * pricemult;
    char stringprice[32];
    snprintf(stringprice, sizeof(stringprice), "Buy jerry farm[%d J]", priceFarm);
    gtk_button_set_label(GTK_BUTTON(farm), stringprice);

  }
}

void FacilityBuy(GtkWidget *facility){
  if(jerriesC >= priceFacility){
    jerriesC = jerriesC - priceFacility;
    facilitiesC++;
    char readingline[100];

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    int pricemult = facilitiesC/10;
    pricemult = pricemult+1;
    priceFacility = 1000 * pricemult;
    char stringprice[32];
    snprintf(stringprice, sizeof(stringprice), "Buy jerry facility[%d J]", priceFacility);
    gtk_button_set_label(GTK_BUTTON(facility), stringprice);

  }
}

void FactoryBuy(GtkWidget *factory){
  if(jerriesC >= priceFactory){
    jerriesC = jerriesC - priceFactory;
    factoriesC++;
    char readingline[100];

    snprintf(readingline, sizeof(readingline), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
    jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
    gtk_label_set_text(GTK_LABEL(jerrycount), readingline);

    int pricemult = factoriesC/10;
    pricemult = pricemult+1;
    priceFactory = 10000 * pricemult;
    char stringprice[32];
    snprintf(stringprice, sizeof(stringprice), "Buy jerry factory[%d J]", priceFactory);
    gtk_button_set_label(GTK_BUTTON(factory), stringprice);

  }
}


void JerryClick(GtkWidget *buttonclicker, gpointer data)
{
  int jerryadd = 1;
  int tempadd;
  jerryadd = jerryadd+autoclickerC;
  tempadd = 2*farmsC;
  jerryadd = jerryadd+tempadd;
  tempadd = 5*facilitiesC;
  jerryadd = jerryadd+tempadd;
  tempadd = 7*factoriesC;
  jerryadd = jerryadd+tempadd;

  jerriesC = jerriesC+jerryadd;

  char readingline2[100];

  snprintf(readingline2, sizeof(readingline2), "%d jerries\n%d autoclickers\n%d farms\n%d facilities\n%d factories",
  jerriesC, autoclickerC, farmsC, facilitiesC, factoriesC);
  gtk_label_set_text(GTK_LABEL(jerrycount), readingline2);

}

int main(int argc, char ** argv)
{
  gtk_init(&argc, &argv);
  GtkWidget *window, *grid, *title, *buttonclicker, *autoclicker, *win;
  GtkWidget *autoclickercount, *factory, *farm, *facility, *savebutton, *start;
  GtkWidget *image;

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
  g_signal_connect(autoclicker, "clicked", G_CALLBACK(AutoClickerBuy), NULL);

  factory = gtk_button_new_with_label("Buy jerry factory[10000 J]");
  gtk_grid_attach(GTK_GRID(grid), factory, 3,3,1,1);
  g_signal_connect(factory, "clicked", G_CALLBACK(FactoryBuy), NULL);

  farm = gtk_button_new_with_label("Buy jerry farm[200 J]");
  gtk_grid_attach(GTK_GRID(grid), farm, 1,2,1,1);
  g_signal_connect(farm, "clicked", G_CALLBACK(FarmBuy), NULL);

  facility = gtk_button_new_with_label("Buy jerry facility[1000 J]");
  gtk_grid_attach(GTK_GRID(grid), facility, 1,3,1,1);
  g_signal_connect(facility, "clicked", G_CALLBACK(FacilityBuy), NULL);


  jerrycount = gtk_label_new("0 jerries\n0 autoclickers\n0 farms\n0 facilities\n0 factories");
  gtk_grid_attach(GTK_GRID(grid), jerrycount, 3, 1, 1, 1);

  savebutton = gtk_button_new_with_label("Save");
  g_signal_connect(savebutton, "clicked", G_CALLBACK(SaveData), NULL);
  gtk_grid_attach(GTK_GRID(grid), savebutton, 1,4,1,1);

  win = gtk_button_new_with_label("win the game [2000000000 J]");
  gtk_grid_attach(GTK_GRID(grid), win, 3,4,1,1);
  g_signal_connect(win, "clicked", G_CALLBACK(Win), NULL);

  lines = 1;

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

  int pricemult = autoclickerC/10;
  pricemult = pricemult+1;
  priceAuto = 10 * pricemult;
  char stringprice[32];
  snprintf(stringprice, sizeof(stringprice), "Buy jerry clicker[%d J]", priceAuto);
  gtk_button_set_label(GTK_BUTTON(autoclicker), stringprice);

  pricemult = farmsC/10;
  pricemult = pricemult+1;
  priceFarm = 200 * pricemult;
  snprintf(stringprice, sizeof(stringprice), "Buy jerry farm[%d J]", priceFarm);
  gtk_button_set_label(GTK_BUTTON(farm), stringprice);

  pricemult = facilitiesC/10;
  pricemult = pricemult+1;
  priceFacility = 1000 * pricemult;
  snprintf(stringprice, sizeof(stringprice), "Buy jerry facility[%d J]", priceFacility);
  gtk_button_set_label(GTK_BUTTON(facility), stringprice);

  pricemult = factoriesC/10;
  pricemult = pricemult+1;
  priceFactory = 10000 * pricemult;
  snprintf(stringprice, sizeof(stringprice), "Buy jerry factory[%d J]", priceFactory);
  gtk_button_set_label(GTK_BUTTON(factory), stringprice);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show_all(window);
  gtk_main();



  return 0;
}
