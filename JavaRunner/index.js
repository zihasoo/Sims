let result = document.getElementById("result");
let dropdown = document.getElementById("dropdown");
let output_box = document.getElementById("output_box");
let editor = ace.edit(document.getElementById("code_area"), {
  theme: "ace/theme/cobalt",
  mode: "ace/mode/java",
});
let input_box = document.getElementById("input_box");

let colors = {
  cobalt: "#052440",
  dracula: "#303440",
  dreamweaver: "#ffffff",
  one_dark: "#282C34",
  monokai: "#272822",
  github: "#ffffff",
};

function change_theme() {
  input_box.style.backgroundColor = colors[dropdown.value];
  output_box.style.backgroundColor = colors[dropdown.value];
  editor.setTheme("ace/theme/" + dropdown.value);
}

function compile_code() {
  let url = "https://runjava.mcv.kr/runCode";
  let body;

  if (input_box.value !== "") {
    url += "WithInput";
    body = JSON.stringify({ code: editor.getValue(), input: input_box.value });
  } else {
    body = editor.getValue();
  }

  fetch(url, {
    method: "POST",
    body: body,
  })
    .then(async (response) => {
      result.textContent = await response.text();
    })
    .catch((err) => console.error(err));
}

dropdown.addEventListener("change", change_theme);
document.getElementById("submit_btn").addEventListener("click", compile_code);
