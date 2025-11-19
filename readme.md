# Documentation technique

## Récupérer le dépôt (initialisation)

```bash
git clone https://github.com/antton-dev/PX221-Othello.git
```

La racine du projet est donc :

```
PX221-Othello/
```
(C'est le dossier où se trouve le `.git`)

---

## Workflow de modification (branche master protégée)
**Toute nouvelle modification passe obligatoirement par une nouvelle branche**

### 1. Récupérer la dernière version distante 
```bash
git pull
```

### 2. Créer une branche dédiée pour la modification
Toutes les modifications doivent être faites dans une **nouvelle branche**, pas sur `master`.

```bash
git switch -c nom_branche
```
Le nom de la branche doit être synthétique et court. Pas d'espace.

### 3. Faire les modifications du code

Modifier les fichiers nécessaires.

### 4. Ajouter et valider les modifications

```bash
git add .
git commit -m "description claire des changements"
```

### 5. Pousser la branche sur GitHub

```bash
git push -u origin nom_branche
```

### 6. Ouvrir une Pull Request

1. Aller sur GitHub → dépôt du projet  
2. GitHub proposera automatiquement une Pull Request pour la branche poussée (Bouton vert Create Pull Request)
3. Créer la PR vers **master**  
4. Le message suivant doit s'afficher 
>No conflicts with base branch
>Merging can be performed automatically.
5. Si pas d'erreur, cliquer sur **Squash and Merge**. Le message suivant doit apparaitre : 
>Pull request successfully merged and closed
>You're all set — the branch can be safely deleted.
6. Supprimer la branche sur Github : **Delete branch** dans l'onglet de la PR.

### 7. Cleaner la version locale
1. En local, revenir sur la branche principale `master` : 
```bash
git switch master
```
2. Récupérer la dernière version : 
```bash
git pull
```

3. Supprimer la branche :
```bash
git branch -d nom_branche
```


---

## Résumé

- `master` est protégée : impossible de push dessus directement  
- Tout passe par : **branche → commits → push → PR → merge**
