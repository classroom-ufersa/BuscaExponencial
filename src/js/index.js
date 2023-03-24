const searchField = document.getElementById("searchField");
const tableOfStudents = document.querySelectorAll("td");
let studentName = document.querySelector("[data-js=nomeAluno]");
let studentEnrollment = document.querySelector("[data-js=matriculaAluno]");
let studentDocument = document.querySelector("[data-js=documentoAluno]");

const arrOfNames = [];

class ExponentialSearch {
  constructor(table) {
    this.table = table;
  }

  pushingArray() {
    const listOfNames = this.table;

    let count = 0;
    for (let i = 0; i < 20; i++) {
      let nomes = {
        nome: listOfNames[count].innerText,
        matricula: listOfNames[count + 1].innerText,
        documento: listOfNames[count + 2].innerText
      };
      count += 3;
      arrOfNames.push(nomes);
    }

    // ordenando em ordem alfabética
    arrOfNames.sort((nome1, nome2) => {
      if (nome1.nome < nome2.nome) {
        return -1;
      } else if (nome1.nome > nome2.nome) {
        return 1;
      } else {
        return 0;
      }
    });
  }

  exponentialSearch(name) {
    let n = arrOfNames.length;
    if (arrOfNames[0].nome == name) {
      return 0;
    }

    let i = 1;
    while (i < n && arrOfNames[i].nome <= name) {
      i *= 2;
    }

    return this.binarySearch(Math.floor(i / 2), Math.min(i, n - 1), name);
  }

  binarySearch(start, end, name) {
    while (start <= end) {
      let mid = Math.floor(start + (end - start) / 2);
      if (arrOfNames[mid].nome == name) {
        return mid;
      } else if (arrOfNames[mid].nome < name) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return -1;
  }

  updatedModal(e) {
    let index = this.exponentialSearch(e);
    studentName.innerText = `Nome: ${arrOfNames[index].nome}`
    studentEnrollment.innerText =`Matricula: ${arrOfNames[index].matricula}`
    studentDocument.innerText =`Documento: ${arrOfNames[index].documento}`
  }
}

let newTable = new ExponentialSearch(tableOfStudents);
newTable.pushingArray();

searchField.addEventListener("change", (e) => {
  newTable.updatedModal(e.target.value);
});

/* =======================  MODAL  ======================= */
document.addEventListener("DOMContentLoaded", () => {
  // Functions to open and close a modal
  function openModal($el) {
    $el.classList.add("is-active");
  }

  function closeModal($el) {
    $el.classList.remove("is-active");
  }

  function closeAllModals() {
    (document.querySelectorAll(".modal") || []).forEach(($modal) => {
      closeModal($modal);
    });
  }

  // Add a click event on buttons to open a specific modal
  (document.querySelectorAll(".js-modal-trigger") || []).forEach(($trigger) => {
    const modal = $trigger.dataset.target;
    const $target = document.getElementById(modal);

    $trigger.addEventListener("click", () => {
      openModal($target);
    });
  });

  // Add a click event on various child elements to close the parent modal
  (
    document.querySelectorAll(
      ".modal-background, .modal-close, .modal-card-head .delete, .modal-card-foot .button"
    ) || []
  ).forEach(($close) => {
    const $target = $close.closest(".modal");

    $close.addEventListener("click", () => {
      closeModal($target);
    });
  });

  // Add a keyboard event to close all modals
  document.addEventListener("keydown", (event) => {
    const e = event || window.event;

    if (e.keyCode === 27) {
      // Escape key
      closeAllModals();
    }
  });
});
