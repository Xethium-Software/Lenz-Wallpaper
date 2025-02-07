import os
import subprocess

def ensure_raylib_cloned():
    external_folder = "external"
    raylib_folder = os.path.join(external_folder, "raylib")
    repo_url = "https://github.com/raysan5/raylib.git"
    
    if not os.path.exists(raylib_folder):
        print("raylib folder not found. Cloning repository...")
        os.makedirs(external_folder, exist_ok=True)
        try:
            subprocess.run(["git", "clone", repo_url, raylib_folder], check=True)
            print("Cloning successful!")
        except subprocess.CalledProcessError:
            print("Error: Failed to clone raylib repository.")
    else:
        print("raylib folder already exists. No action needed.")

if __name__ == "__main__":
    ensure_raylib_cloned()
