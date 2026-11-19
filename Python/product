from time import sleep

General = {}
code_dict = {}

text = """This is the first time you've opened this program 
So, you need to enter some information to get started"""

for char in text:
    print(char, end="", flush=True)
    sleep(0.05)
sleep(3)
VAT = input("\nPlease Enter VAT Percentage: ").strip("%")
VAT = float(VAT)
VAT_percentage = VAT / 100


def Add_new_product():
    
    flag = False
    flage_1 = False
    
    while True:    
        answer = input("Do you want to add a new category? (yes/no)\n")
        if answer.lower() == "yes" or answer.lower() == "y":
            while True:
                new_category = input("Enter new category: ")
                if new_category in General.keys():
                    print("This category already exists")
                else: 
                    product_name = input("Enter the new product name: ")
                    product_purchase = input("Product purchase price: ")
                    product_sell = input("Product selling price: ")
                    product_code = input("Product code: ")
                    product_inventory = input("Product inventory: ")
                    break
            flag = True
            break

        elif answer.lower() == "no" or answer.lower() == "n":
            if General != {}:
                flage_1 = True
                while True:
                    product_category = input("Please Enter Product category: ")
                    if product_category not in General.keys():
                        print("This category does not exist")
                    else:        
                        product_name = input("Enter the new product name: ")
                        product_purchase = input("Product purchase price: ")
                        product_sell = input("Product selling price: ")
                        while True:
                            product_code = input("Product code: ")
                            if product_code in code_dict.keys():
                                print("This code already exists")
                            else:
                                break
                        product_inventory = input("Product inventory: ")
                        break   
            else:
                print("Product list is empty")
                sleep(2)
            break

        else:
            print("invalid asnwer")
            sleep(2)

    if flag:
        General[new_category] = {}
        General[new_category][product_name] = []
        General[new_category][product_name].append(new_category)
        General[new_category][product_name].append(product_name)
        General[new_category][product_name].append(product_purchase)
        General[new_category][product_name].append(product_sell)
        General[new_category][product_name].append(product_code)
        General[new_category][product_name].append(product_inventory)
        code_dict[General[new_category][product_name][4]] = General[new_category][product_name][:]
        
        print("\nNew product added")
        sleep(2)
        return_to_menu = input("\n(To return to the menu please press enter)")
    
    else:
        
        if flage_1:
            General[product_category][product_name] = []
            General[product_category][product_name].append(product_category)
            General[product_category][product_name].append(product_name)
            General[product_category][product_name].append(product_purchase)
            General[product_category][product_name].append(product_sell)
            General[product_category][product_name].append(product_code)
            General[product_category][product_name].append(product_inventory)
            code_dict[General[product_category][product_name][4]] = General[product_category][product_name][:]

            print("\nNew product added")
            sleep(2)
            return_to_menu = input("\n(To return to the menu please press enter)")
    

def Show_product_information():
    
    if General != {}:
        
        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break    
        
        print("\n. Product category: ", General[product_category][product_name][0])
        print(". Product name: ", General[product_category][product_name][1])
        print(". Product purchase price: ", General[product_category][product_name][2])
        print(". Product selling price: ", General[product_category][product_name][3])
        price = float(General[product_category][product_name][3])
        print(". Product price after calculating VAT: ",price + price * VAT_percentage)
        print(". Product code: ", General[product_category][product_name][4])
        print(". Prpduct inventory: ", General[product_category][product_name][5])
        
        return_to_menu = input("\n(To return to the menu please press enter)")
    
    else:
        print("Product list is empty")
        sleep(2)


def Search_product_by_code():
    
    if General != {}:
    
        while True:
            code = input("Enter code: ")
            if code not in code_dict.keys():
                print("Searching ...")
                sleep(1)
                print("Code not found")
            else: 
                break

        print("Searching ...")
        sleep(0.75)
        print("\n. Product category: ", code_dict[code][0])
        print(". Product name: ", code_dict[code][1])
        print(". Product purchase price: ", code_dict[code][2])
        print(". Product selling price: ", code_dict[code][3])
        price = float(code_dict[code][3])
        print(". Product price after calculating VAT: ",price + price * VAT_percentage)
        print(". Product code: ", code_dict[code][4])
        print(". Prpduct inventory: ", code_dict[code][5])

        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(0.75)


def Edit_product_information():
    
    if General != {}:
    
        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break   
        
        while True: 
            new_product_purchase = input("Please enter new product purchase price: ")
            new_product_sell = input("Please enter new product sell price: ")
            while True:
                new_product_code = input("Please enter new product code: \n(If you don't want to change the code, press Enter)")
                if new_product_code != "" and new_product_code in code_dict.keys():
                    print("This code already exists")
                else:
                    break    
            new_product_inventory = input("Please enter new product inventory: ")
            answer = input("\nAre you sure about changes? (yes/no) ")
            if answer.lower() == "yes" or answer.lower() == "y":
                General[product_category][product_name][2] = new_product_purchase
                General[product_category][product_name][3] = new_product_sell
                if new_product_code != "":    
                    del code_dict[General[product_category][product_name][4]]
                    General[product_category][product_name][4] = new_product_code
                    General[product_category][product_name][5] = new_product_inventory
                    code_dict[General[product_category][product_name][4]] = General[product_category][product_name][:]
                else:
                    General[product_category][product_name][5] = new_product_inventory
                    code_dict[General[product_category][product_name][5]] = new_product_inventory
                print("\nProduct information has been updated")
                sleep(2)
                break
        
        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)


def Delete_product():
    
    if General != {} :
    
        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break   

        while True: 
            answer = input("Are you sure about deleting this product? (yes/no) ")
            if answer.lower() == "yes" or answer.lower() == "y":
                del code_dict[General[product_category][product_name][4]]
                del General[product_category][product_name]
                if General[product_category] == {}:
                    del General[product_category]
                print("\nThe desired product was successfully deleted")
                sleep(2)
                break
            else:
                break

        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)            


def Show_all_products():
    
    if General != {} : 
    
        for main_key, inner_dict in General.items():
            print(f"{main_key}:")
            for inner_key in inner_dict:
                print(f"- {inner_key}")
            print()  
        
        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)


def Add_new_price_for_product():
    
    if General != {}:
    
        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break   

        new_product_purchase = input("Please enter new product purchase price: ")
        new_product_sell = input("Please enter new product sell price: ")
        
        
        answer = input("Are you sure about changing this product price? (yes/no) ")
        if answer.lower() == "yes" or answer.lower() == "y":
            General[product_category][product_name][2] = new_product_purchase
            General[product_category][product_name][3] = new_product_sell
            code_dict[General[product_category][product_name][4]][2] = new_product_purchase
            code_dict[General[product_category][product_name][4]][3] = new_product_sell
            print("\nProduct price updated")
            sleep(2)

        
        return_to_menu = input("\n(To return to the menu please press enter)")
    
    else:
        print("Product list is empty")
        sleep(2)


def Add_a_discount_for_product():
    
    if General != {}:

        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break   

        while True: 
            discount = input("Enter discount percentage: ").strip("%")
            if float(discount) < 0 or float(discount) > 100:
                print("Invalid number")
            else:
                break
        discount_percentage = 100 - float(discount)
        price = float(General[product_category][product_name][3])
        discount_product = price * discount_percentage / 100
        General[product_category][product_name][3] = str(discount_product)
        del code_dict[General[product_category][product_name][4]]
        code_dict[General[product_category][product_name][4]] = General[product_category][product_name][:]

        print("\nDiscount applied")
        sleep(2)
        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)

def inventory_update():
    
    if General != {}:
    
        while True: 
            product_category = input("Please Enter the desired product category: ")
            if product_category not in General.keys():
                print("This category does not exist")
            else:
                break
        while True:
            product_name = input("Please Enter the product name: ")   
            if product_name not in General[product_category].keys():
                print("This product does not exist")
            else:
                break

        inventory_update = int(input("Please Enter product inventory changes: "))
        inventory = General[product_category][product_name][5]
        inventory = int(inventory) + inventory_update
        General[product_category][product_name][5] = str(inventory)
        code_dict[General[product_category][product_name][4]][5] = str(inventory)

        print("\nInventory updated")
        sleep(2)
        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)

def Current_inventory_report():
    
    if General != {}:
    
        for main_key, inner_dict in General.items():
            print(f"{main_key}:")
            for inner_key, value in inner_dict.items():
                print(f"- {inner_key} : {value[5]}")
            print()  
        
        return_to_menu = input("\n(To return to the menu please press enter)")

    else:
        print("Product list is empty")
        sleep(2)


def main():
    
    while True:
        print("\nProduct Management:")
        print("\t1. Add new product")
        print("\t2. Show product information")
        print("\t3. Search product by code")
        print("\t4. Edit product information")
        print("\t5. Delete product")
        print("\t6. Show all products")
        print("Price Management:")
        print("\t7. Add new price for product")
        print("\t8. Add a discount for product")
        print("Inventory Management:")
        print("\t9. Inventory update")
        print("\t10. Current inventory report")
        print("11. Exit\n") 
    
        answer = input()
        answer == answer.lower()
            
        if answer == "1" or answer == "add new product":
            Add_new_product()

        elif answer == "2" or answer == "show product information":
            Show_product_information()
        
        elif answer == "3" or answer == "search product by code":
            Search_product_by_code()
        
        elif answer == "4" or answer == "edit product information":
            Edit_product_information()
            
        elif answer == "5" or answer == "delete product":
            Delete_product()
        
        elif answer == "6" or answer == "show all products":
            Show_all_products()
        
        elif answer == "7" or answer == "add new price for product":
            Add_new_price_for_product()
        
        elif answer == "8" or answer == "add a discount for product":
            Add_a_discount_for_product()
        
        elif answer == "9" or answer == "inventory update":
            inventory_update()
        
        elif answer == "10" or answer == "current inventory report":
            Current_inventory_report()
        
        elif answer == "11" or answer == "exit":
            break

        else:
            print("Invalid choice ")
            sleep(2)
        

main()
