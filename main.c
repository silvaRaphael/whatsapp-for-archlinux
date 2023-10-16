#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

static void destroy_cb(GtkWidget* widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GdkPixbuf *icon = gdk_pixbuf_new_from_file_at_size("./logo.png", 64, 64, NULL);
    gtk_window_set_icon(GTK_WINDOW(window), icon);
    gtk_window_set_title(GTK_WINDOW(window), "Whatsapp");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    g_signal_connect(window, "destroy", G_CALLBACK(destroy_cb), NULL);

    WebKitWebView* webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));

    const gchar* url = "https://web.whatsapp.com";
    webkit_web_view_load_uri(webview, url);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
