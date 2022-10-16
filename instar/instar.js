const btn = document.querySelector(".btn");
const inputId = document.querySelector(".inputId");
const inputPw = document.querySelector(".inputPw");

btn.addEventListener("click", function () {
  if (inputId.value === "jaeyoon" && inputPw.value === "1111") {
    alert("로그인 성공");
  } else {
    alert("로그인 실패");
    btn.disabled = true;
    inputId.value = "";
    inputPw.value = "";
    btn.classList.remove("active");
  }
});

inputPw.addEventListener("keyup", function () {
  if (inputId.value) {
    btn.disabled = false;
    btn.classList.add("active");
  }
  if (!inputPw.value) {
    btn.disabled = true;
    btn.classList.remove("active");
  }
});
inputId.addEventListener("keyup", function () {
  if (inputPw.value) {
    btn.disabled = false;
    btn.classList.add("active");
  }
  if (!inputId.value) {
    btn.disabled = true;
    btn.classList.remove("active");
  }
});
