﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Storage;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace pz_23
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
        }

        private void AddBookmark_Click(object sender, RoutedEventArgs e)
        {
            // Получаем URL из адресной строки
            string url = urlTextBox.Text.Trim();

            if (!string.IsNullOrEmpty(url))
            {
                //новый пункт меню для закладок
                MenuFlyoutItem bookmarkItem = new MenuFlyoutItem
                {
                    Text = url,
                    Tag = url
                };

                // Добавляем обработчик события клика на закладку
                bookmarkItem.Click += BookmarkItem_Click;

                // Добавляем закладку в меню
                bookmarksFlyout.Items.Add(bookmarkItem);
            }
        }

        // Обработчик события клика на закладке
        private void BookmarkItem_Click(object sender, RoutedEventArgs e)
        {
            // Получаем URL из тега закладки
            string url = ((MenuFlyoutItem)sender).Tag.ToString();

            // Загрузка страницы в WebView
            webView.Navigate(new Uri(url));
        }
    }
}