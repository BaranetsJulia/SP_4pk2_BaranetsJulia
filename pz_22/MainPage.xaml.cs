using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

namespace pz_22
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private Dictionary<string, double> prices = new Dictionary<string, double>()
        {
            { "Мороженое", 5.99 },
            { "Шоколад", 15.99 },
            { "Пирожное", 10.50 },
            { "Чизкейк", 34.99 },
            { "Кофе", 7.99 },
            { "Чай с лимоном", 4.99 },
            { "Лимонад", 6.00 },
            { "Вода", 2.00 },
            { "Пончики", 8.50 },
            { "Бисквитный рулет", 17.00 },
            { "Молочные коржики", 9.30 }
        };

        public MainPage()
        {
            this.InitializeComponent();
        }

        private void CreateOrderButton_Click(object sender, RoutedEventArgs e)
        {
            double totalPrice = 0;
            List<string> selectedItems = new List<string>();

            if (IceCreamCheckBox.IsChecked == true)
            {
                totalPrice += prices["Мороженое"];
                selectedItems.Add("Мороженое");
            }
            if (ChocolateCheckBox.IsChecked == true)
            {
                totalPrice += prices["Шоколад"];
                selectedItems.Add("Шоколад");
            }
            if (CakeCheckBox.IsChecked == true)
            {
                totalPrice += prices["Пирожное"];
                selectedItems.Add("Пирожное");
            }
            if (CheesecakeCheckBox.IsChecked == true)
            {
                totalPrice += prices["Чизкейк"];
                selectedItems.Add("Чизкейк");
            }
            if (CoffeeCheckBox.IsChecked == true)
            {
                totalPrice += prices["Кофе"];
                selectedItems.Add("Кофе");
            }
            if (TeaCheckBox.IsChecked == true)
            {
                totalPrice += prices["Чай с лимоном"];
                selectedItems.Add("Чай с лимоном");
            }
            if (LemonadeCheckBox.IsChecked == true)
            {
                totalPrice += prices["Лимонад"];
                selectedItems.Add("Лимонад");
            }
            if (WaterCheckBox.IsChecked == true)
            {
                totalPrice += prices["Вода"];
                selectedItems.Add("Вода");
            }
            if (DonutsCheckBox.IsChecked == true)
            {
                totalPrice += prices["Пончики"];
                selectedItems.Add("Пончики");
            }
            if (RollCheckBox.IsChecked == true)
            {
                totalPrice += prices["Бисквитный рулет"];
                selectedItems.Add("Бисквитный рулет");
            }     
            if (MilkCakesCheckBox.IsChecked == true)
            {
                totalPrice += prices["Молочные коржики"];
                selectedItems.Add("Молочные коржики");
            }

            string orderSummary = string.Join(", ", selectedItems);

            OrderSummaryTextBlock.Text = orderSummary;
            TotalPriceTextBlock.Text = $"Стоимость заказа: {totalPrice.ToString("0.00")} руб.";
        }
    }
}