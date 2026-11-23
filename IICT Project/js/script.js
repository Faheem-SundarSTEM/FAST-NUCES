if (document.getElementById("days")) {
    const eventDate = new Date("2026-12-16T10:00:00+05:00");

    function updateCountdown() {
    
        let remaining = eventDate - new Date(); /* subtracting the current date and time from the event date and time to calculate the remaining milliseconds. */

        let totalSeconds = Math.floor(remaining / 1000); /* math floor round down the decimal and /1000 Converts milliseconds to seconds */

        if (totalSeconds < 0) {
            totalSeconds = 0;
        }

        let days = Math.floor(totalSeconds / 86400); /* 86400s are there in one day */
        let hours = Math.floor((totalSeconds % 86400) / 3600); /* 3600s in one day */
        let minutes = Math.floor((totalSeconds % 3600) / 60); /* 60s in one min */
        let seconds = totalSeconds % 60;

        document.getElementById("days").textContent = days;
        document.getElementById("hours").textContent = hours;
        document.getElementById("mins").textContent = minutes;
        document.getElementById("seconds").textContent = seconds;
    }

    updateCountdown();
    setInterval(updateCountdown, 1000); 
}

/* Dark and Light Theme Toggle */

const themeButton = document.getElementById("theme-toggle");
const logo = document.getElementById("theme-logo");

/* one function that applies a theme and remembers it */
function setTheme(theme) {
    document.documentElement.setAttribute("data-theme", theme);
    logo.src = "images/logo-" + theme + ".png";   /* logo-dark.png or logo-light.png */
    themeButton.textContent = (theme === "dark") ? "LIGHT MODE" : "DARK MODE";
    localStorage.setItem("theme", theme);          /* saves the choice in the browser */
}

/* when a page loads, use the saved theme if there is one */
const savedTheme = localStorage.getItem("theme");
if (savedTheme) {
    setTheme(savedTheme);
}

/* when the button is clicked, switch to the other theme */
themeButton.addEventListener("click", function() {
    const currentTheme = document.documentElement.getAttribute("data-theme");
    setTheme(currentTheme === "dark" ? "light" : "dark");
});
/* Contact and Event Proposal Form Validation */

const form = document.getElementById("proposal-form");

if (form) {
    form.addEventListener("submit", function(event) {
        event.preventDefault(); /* stops the page from reloading */

        let valid = true;

        const name = document.getElementById("name").value.trim();
        const email = document.getElementById("email").value.trim();
        const society = document.getElementById("society").value.trim();
        const date = document.getElementById("event-date").value;
        const message = document.getElementById("message").value.trim();

        /* clear old messages */
        document.querySelectorAll(".error-msg").forEach(function(e) { e.textContent = ""; });
        document.getElementById("success-msg").style.display = "none";

        if (name === "") {
            document.getElementById("name-error").textContent = "Name is required.";
            valid = false;
        }

        /* email must look like something@something.something */
        if (!/^\S+@\S+\.\S+$/.test(email)) {
            document.getElementById("email-error").textContent = "Enter a valid email address.";
            valid = false;
        }

        if (society === "") {
            document.getElementById("society-error").textContent = "Society name is required.";
            valid = false;
        }

        /* the event date must be after today */
        if (date === "" || new Date(date) <= new Date()) {
            document.getElementById("date-error").textContent = "Choose a future date.";
            valid = false;
        }

        if (message === "") {
            document.getElementById("message-error").textContent = "Message is required.";
            valid = false;
        }

        if (valid) {
            document.getElementById("success-msg").style.display = "block";
            form.reset();
        }
    });
}


/* Events Page: Category Filter */

const filterButtons = document.querySelectorAll(".filter-btn");
const eventColumns = document.querySelectorAll(".event-col");

filterButtons.forEach(function(button) {
    button.addEventListener("click", function() {
        const filter = button.getAttribute("data-filter");

        filterButtons.forEach(function(b) { b.classList.remove("active"); });
        button.classList.add("active");

        eventColumns.forEach(function(col) {
            /* show the card if "all" is chosen or the category matches */
            if (filter === "all" || col.getAttribute("data-category") === filter) {
                col.classList.remove("d-none");
            } else {
                col.classList.add("d-none");
            }
        });
    });
});

/* Events Page: Fill the Modal with the clicked event's details */

document.querySelectorAll(".event-card").forEach(function(card) {
    card.addEventListener("click", function() {
        document.getElementById("modal-title").textContent = card.getAttribute("data-title");
        document.getElementById("modal-date").textContent = card.getAttribute("data-date");
        document.getElementById("modal-time").textContent = card.getAttribute("data-time");
        document.getElementById("modal-venue").textContent = card.getAttribute("data-venue");
        document.getElementById("modal-desc").textContent = card.getAttribute("data-desc");
    });
});
