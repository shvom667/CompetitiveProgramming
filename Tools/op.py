from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Path to the geckodriver executable (replace with your own path)
geckodriver_path = '/usr/bin/geckodriver'

# Set Firefox options
options = Options()
#options.add_argument("--headless")  # Optional: Run Firefox in headless mode (no GUI)
options.add_argument("--profile=/home/shivom/snap/firefox/common/.mozilla/firefox/nm2aq31r.test")

# Create a new instance of the GeckoDriver service
service = Service(executable_path=geckodriver_path)
#driver = webdriver.Firefox(service=service, options=options)

# Create a new instance of the Firefox browser with the specified profile
#fucntion for login
driver = webdriver.Firefox(service=service, options=options)
my_id = 'soneci6388@haislot.com'
my_passwd = '9Vhj)w4$}CA",gs'
problem_link = 'https://codeforces.com/problemset/problem/4/A'  # Example problem link
def login_to_codeforces(username=my_id, password=my_passwd):
    # Set Firefox options
    options = webdriver.FirefoxOptions()
    # options.add_argument("--headless")  # Optional: Run Firefox in headless mode (no GUI)

    # Path to the geckodriver executable (replace with your own path)
    geckodriver_path = '/usr/bin/geckodriver'

    # Create a new instance of the Firefox browser

    # Navigate to Codeforces.com
    driver.get('https://codeforces.com')

    # Click the login link to open the login form
    login_link = driver.find_element(By.LINK_TEXT, 'Enter')
    login_link.click()

    # Wait for the login form to load
    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.ID, 'handleOrEmail')))

    # Find the username and password input fields and enter your credentials
    username_field = driver.find_element(By.ID, 'handleOrEmail')
    username_field.send_keys(username)
    password_field = driver.find_element(By.ID, 'password')
    password_field.send_keys(password)

    # Click the login button to submit the form
    login_button = driver.find_element(By.CLASS_NAME, 'submit')
    login_button.click()

    # Wait for the login to complete (you may need to add additional logic to wait for the login to succeed)
    #WebDriverWait(driver, 10).until(EC.url_matches('https://codeforces.com/'))
    driver.get(problem_link)
    submit_button = driver.find_element(By.LINK_TEXT, 'Submit')
    submit_button.click()

    return driver

#function complete
login_to_codeforces()
time.sleep(1000);

# Close the browser
driver.quit()

