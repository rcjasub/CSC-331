function Calculate() {
    // Convert input values from strings to numbers
    const principal = parseFloat(document.getElementById('principal').value);
    const rate = parseFloat(document.getElementById('rate').value);
    const time = parseFloat(document.getElementById('time').value);

    // Perform the calculations
    const simpleInterest = (principal * rate * time) / 100;
    const totalAmount = principal + simpleInterest;

    // Display the results, formatted to two decimal places
    document.getElementById('simpleI').value = simpleInterest.toFixed(2);
    document.getElementById('principalPlusI').value = totalAmount.toFixed(2);

    localStorage.setItem('simpleInterest', simpleInterest.toFixed(2));
    localStorage.setItem('totalAmount', totalAmount.toFixed(2));
}

// Select the button by its ID
const calcItBtn = document.getElementById("calc-btn");
if (calcItBtn) {
    calcItBtn.addEventListener("click", Calculate);
}

function Display() {
    const savedSI = localStorage.getItem('simpleInterest');
    const savedTotal = localStorage.getItem('totalAmount');

    if (savedSI && savedTotal) {
        alert(`Simple Interest: $${savedSI}\nTotal Amount: $${savedTotal}`);
    } else {
        alert("No calculation found.");
    }
}
